/*
COMP 3008 - Project 2 - Team: ROBOTS
CSV Processing Program
 */

package main

import (
	"encoding/csv"
	"fmt"
	"io"
	"os"
	"time"
)

// CSV location strings
var textLocation	string = "./Working Logs/text21.csv"
var imageLocation	string = "./Working Logs/imagept21.csv"
var finalLocation	string = "./Working Logs/dataOut.csv"

// Declaration of list variables
var textDataList	dataList
var imageDataList	dataList
var	combinedData	dataList
var users			userList

// Declaration of CSV data objects
var imageData	CSVData
var textData	CSVData

//  Declaration of list types
type userList []*userData
type dataList []CSVData



// Struct for storing original CSV values
type CSVData struct {
	Time			string
	User			string
	Site			string
	Scheme			string
	Mode			string
	Event			string
	EventDetails	string
	Data			string
}

// Struct for storing user data
type userData struct {
	User				string
	Scheme				string
	TotalAttempts		int
	SuccessfulAttempts	int
	FailedAttempts		int
	SuccessfulTime		[]string
	FailedTime			[]string
}

// ReadCSV reads the CSV at location.
// It returns the data as an array of lines.
func ReadCsv(location string) ([][]string, error) {

	f, err := os.Open(location)
	if err != nil {
		return [][]string{}, err
	}
	defer f.Close()

	lines, err := csv.NewReader(f).ReadAll()
	if err != nil {
		return [][]string{}, err
	}

	return lines, nil
}

// loadTextData loads the data from text21.csv into a CSVData object.
func loadTextData() {
	lines, err := ReadCsv(textLocation)
	if err != nil {
		panic(err)
	}

	for _, line := range lines {
		data := CSVData{
			Time:			line[0],
			User:			line[1],
			Site:			line[2],
			Scheme:			line[3],
			Mode:			line[4],
			Event:			line[5],
			EventDetails:	line[6],
			Data:			line[7],
		}

		textDataList = append(textDataList, data)

		//fmt.Println(data.Time + " " + data.User + " " + data.Site + " " + data.Scheme + " " + data.Mode + " " + data.Event + " " + data.EventDetails + " " + data.Data)
	}
}

// loadImageData loads the data from imagept21.csv into a CSV data object
func loadImageData() {
	lines, err := ReadCsv(imageLocation)
	if err != nil {
		panic(err)
	}

	for _, line := range lines {
		data := CSVData{
			Time:			line[0],
			User:			line[1],
			Site:			line[2],
			Scheme:			line[3],
			Mode:			line[4],
			Event:			line[5],
			EventDetails:	line[6],
			Data:			line[7],
		}

		imageDataList = append(imageDataList, data)
		//fmt.Println(data.Time + " " + data.User + " " + data.Site + " " + data.Scheme + " " + data.Mode + " " + data.Event + " " + data.EventDetails + " " + data.Data)
	}
}

// encode encodes an object into CSV format
// The method takes the data from a *userList and writes it to an io.writer object
// It returns an error
func (data *userList) encode(w io.Writer) error {
	n := csv.NewWriter(w)
	err := n.Write([]string{"UserID", "Scheme", "Total Attempts", "Successful Attempts", "Failed Attempts", "Successful Times (s)", "Failed Times (s)"})
	if err != nil {
		return err
	}
	for _, v := range *data {
		err := n.Write([]string{
			v.User,
			v.Scheme,
			fmt.Sprintf("%d", v.TotalAttempts),
			fmt.Sprintf("%d", v.SuccessfulAttempts),
			fmt.Sprintf("%d", v.FailedAttempts),
			fmt.Sprintf("%v", v.SuccessfulTime),
			fmt.Sprintf("%v", v.FailedTime)})
		if err != nil {
			return err
		}
	}

	n.Flush()
	return n.Error()
}

// saveData saves the users to a file
func saveData() {
	f, err := os.Create(finalLocation)
	if err != nil {
		panic(err)
	}
	defer f.Close()

	users.encode(f)
}

// convertScheme converts the password scheme into the requested format
// It takes in a pointer to a string
func convertScheme(str* string) {
	if *str == "testpasstiles" {
		*str = "Image21"
	}

	if *str == "testtextrandom" {
		*str = "Text21"
	}
}

// getLoginData calculates and applies the login data to each user add appends the user to the user list
func (data dataList) getLoginData(users* userList) {
	var startTime time.Time
	var duration int
	for _, v := range data {
		exists := false
		u := new(userData)
		u.User = v.User
		u.Scheme = v.Scheme
		u.FailedAttempts, u.SuccessfulAttempts, u.TotalAttempts = 0, 0, 0
		if users == nil {
			*users = append(*users, u)
		} else {
			exists = false
			for _, w := range *users {
				if v.User == w.User {
					u = w
					exists = true
					break
				}
			}
		}

		fmt.Println(v.EventDetails)

		if v.EventDetails == "start" && v.Event == "enter" {
			startTime = convertTime(v.Time)
		}

		if v.Event == "enter" && (v.EventDetails == "passwordSubmitted" || v.EventDetails == "order inputPwd") {
			u.TotalAttempts++
			convertTime(v.Time)
		}

		if v.EventDetails == "failure" && v.Event == "login" {
			u.FailedAttempts++
			failTime := convertTime(v.Time)
			duration = calculateDuration(startTime, failTime)
			u.FailedTime = append(u.FailedTime, fmt.Sprintf("%d", duration))
		}

		if v.EventDetails == "success" && v.Event == "login" {
			u.SuccessfulAttempts++
			successTime := convertTime(v.Time)
			duration = calculateDuration(startTime, successTime)
			u.SuccessfulTime = append(u.SuccessfulTime, fmt.Sprintf("%d", duration))
		}

		if !exists {
			*users = append(*users, u)
		}
	}
}

// convertTime is a helper function to convert login time strings to Time objects
// It takes in a time string and returns a Time object
func convertTime(aTime string) time.Time {
	t, _ := time.Parse("2006-01-02 15:04:05", aTime)
	return t
}

// calculateDuration calculates time difference
// It returns an int representing duration in seconds
func calculateDuration(t1 time.Time, t2 time.Time) int {
	dur := t2.Sub(t1)
	return int(dur.Seconds())
}

func main() {
	//Import data from files
	loadTextData()
	loadImageData()

	//Merge data
	for _, v := range textDataList {
		combinedData = append(combinedData, v)
	}
	for _, v := range imageDataList {
		combinedData = append(combinedData, v)
	}

	combinedData.getLoginData(&users)

	//Convert scheme labels
	for _, v := range users {
		convertScheme(&v.Scheme)
	}


	saveData()
}
