/*
(c) 2019 Louis. D. Nel

WARNING:
NOTE: THIS CODE WILL NOT RUN UNTIL YOU ENTER YOUR OWN openweathermap.org APP ID KEY

NOTE: You need to intall the npm modules by executing >npm install
before running this server

Simple express server re-serving data from openweathermap.org
To test:
http://localhost:3000
or
http://localhost:3000/weather?city=Ottawa
to just set JSON response. (Note it is helpful to add a JSON formatter extension, like JSON Formatter, to your Chrome browser for viewing just JSON data.)
*/
const express = require('express')//express framework
const requestModule = require('request')//helpful npm module for easy http requests
const fs = require('fs')
const PORT = 3000//allow environment variable to possible set PORT

/*YOU NEED AN APP ID KEY TO RUN THIS CODE
  GET ONE BY SIGNING UP AT openweathermap.org
*/
const API_KEY = '1fa00f7a73d168196fb8c9bc84554b47'

const app = express()

//Middleware
app.use(express.static(__dirname + '/public'))

var filePath = __dirname + '/views/index.html'; // filepath of index.html
var headerFilePath = __dirname + '/views/header.html';
var footerFilePath = __dirname + '/views/footer.html';

app.get('/recipes.html', (request, response) => { response.redirect('/recipes')})
app.get('/index.html', (request, response) => { response.redirect('/recipes')})
app.get('/', (request, response) => { response.redirect('/recipes')})
app.get('', (request, response) => { response.redirect('/recipes')})

//get method
app.get('/recipes', (request, response) => {
  let url = ''
  let ingredient = request.query.ingredient
  if(!ingredient) {                     //if there's no ingredient then show homepage using index.html
    //console.log("first it comes here")
    response.sendFile(filePath)
  }
  else {
    /*Here we do serverside rendering WITHOUT a template engine. In This
    example partial HTML files are rendered with data placed in between:

    header.html + data + footer.html*/
    // concept from file rendering professor's code
    fs.readFile(headerFilePath, function(err,data){ // reading the file
       if(err){                 // if there is error
         console.log('ERROR: ' + JSON.stringify(err));
         response.writeHead(404);
         response.end(JSON.stringify(err));
         return;
       }
       response.writeHead(200, {'Content-Type': 'text/html'});
       response.write(data);
       response.write(ingredient);
       fs.readFile(footerFilePath, function(err,data){ // reading the rest of th file
          if(err){                 // if there is error
            console.log('ERROR: ' + JSON.stringify(err));
            response.writeHead(404);
            response.end(JSON.stringify(err));
            return;
          }
          response.write(data);
          response.end();
     })
   })
 }
})


// getting the JSON data and formatting it
app.get('/api', (request, response) => {
  let url = ''
  let ingredient = request.query.ingredient
  if(!ingredient) {         //if there is no ingredient in URL
    //console.log("then it comes here")
    url = `https://food2fork.com/api/search?key=${API_KEY}`// showing the homepage
  }
  else {
    //console.log("does it comes here though")
    url = `https://food2fork.com/api/search?key=${API_KEY}&q=${ingredient}`//if there is ingredient in URL then returnd the searced homepage with ingredient
  }
  requestModule.get(url, (err, res, data) => {
    return response.contentType('application/json').json(JSON.parse(data))
  })
})

//start server
app.listen(PORT, err => {
  if(err) console.log(err)
  else {
    console.log(`Server listening on port: ${PORT} CNTL-C to quit`)
    console.log(`To Test the App:`)
    console.log(`http://localhost:3000/recipes.html`)
    console.log(`http://localhost:3000/recipes`)
    console.log(`http://localhost:3000/index.html`)
    console.log(`http://localhost:3000/`)
    console.log(`http://localhost:3000`)
    console.log(`http://localhost:3000/recipes?ingredient=Basil`)
    console.log(`http://localhost:3000/recipes?ingredient=Basil,Cumin`)
  }
})
