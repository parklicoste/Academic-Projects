/*
Client-side javascript for 2406 assignment 1
COMP 2406 (c) Louis D. Nel 2018

*/
let words = [] //array of drag-able lyrics or chord words

//leave this moving word for fun and for using it to
//provide status info to client.
//NOT part of assignment requirements
let movingString = {
  word: "Moving",
  x: 100,
  y: 100,
  xDirection: 1, //+1 for rightwards, -1 for leftwards
  yDirection: 1, //+1 for downwards, -1 for upwards
  stringWidth: 50, //will be updated when drawn
  stringHeight: 24
} //assumed height based on drawing point size


let timer //timer for animation of moving string etc.
let wordBeingMoved //word being dragged by the mouse
let deltaX, deltaY //location where mouse is pressed relative to word origin
let canvas = document.getElementById('canvas1') //our drawing canvas
let fontPointSize = 18 //point size for chord and lyric text
let wordHeight = 20 //estimated height of a string in the editor
let editorFont = 'Courier New' //font for your editor -must be monospace font
let lineHeight = 40 //nominal height of text line
let lyricLineOffset = lineHeight * 5 / 8 //nominal offset for lyric line below chords
let topMargin = 40 //hard coded top margin white space of page
let leftMargin = 40 //hard code left margin white space of page

let transposedByNSemitones = 0 //transposition in semitones

let wordTargetRect = {
  x: 0,
  y: 0,
  width: 0,
  height: 0
} //used for debugging
//rectangle around word boundary


function getWordAtLocation(aCanvasX, aCanvasY) {

  //locate the word near aCanvasX,aCanvasY co-ordinates
  //aCanvasX and aCanvasY are assumed to be X,Y loc
  //relative to upper left origin of canvas

  //used to get the word mouse is clicked on

  let context = canvas.getContext('2d')

  for (let i = 0; i < words.length; i++) {
    let wordWidth = context.measureText(words[i].word).width
    if ((aCanvasX > words[i].x && aCanvasX < (words[i].x + wordWidth)) &&
      (aCanvasY > words[i].y - wordHeight && aCanvasY < words[i].y)) {
      //set word targeting rectangle for debugging
      wordTargetRect = {
        x: words[i].x,
        y: words[i].y - wordHeight,
        width: wordWidth,
        height: wordHeight
      }
      return words[i]
    } //return the word found
  }
  return null //no word found at location
}

function drawCanvas() {

  let context = canvas.getContext('2d')
  let lyricFillColor = 'cornflowerblue'
  let lyricStrokeColor = 'blue'
  let chordFillColor = 'green'
  let transposedChordFillColor = 'orange'
  let chordStrokeColor = 'green'

  context.fillStyle = 'white'
  context.fillRect(0, 0, canvas.width, canvas.height) //erase canvas

  context.font = '' + fontPointSize + 'pt ' + editorFont
  context.fillStyle = 'cornflowerblue'
  context.strokeStyle = 'blue'

  //draw drag-able lyric and chord words
  for (let i = 0; i < words.length; i++) {
    let data = words[i]
    if (data.lyric) {
      context.fillStyle = lyricFillColor
      context.strokeStyle = lyricStrokeColor
    }
    if (data.chord) {
      if (transposedByNSemitones === 0) {
        context.fillStyle = chordFillColor
        context.strokeStyle = chordStrokeColor

      } else {
        context.fillStyle = transposedChordFillColor
        context.strokeStyle = transposedChordFillColor
      }

    }

    context.fillText(data.word, data.x, data.y)
    context.strokeText(data.word, data.x, data.y)
  }

  //draw box around word last targeted with mouse -for debugging
  //context.strokeRect(wordTargetRect.x, wordTargetRect.y, wordTargetRect.width, wordTargetRect.height);

  /*
    context.fillStyle = 'red';
    movingString.stringWidth = context.measureText(	movingString.word).width;
    context.fillText(movingString.word, movingString.x, movingString.y);
	*/


}

function getCanvasMouseLocation(e) {
  //provide the mouse location relative to the upper left corner
  //of the canvas

  /*
  This code took some trial and error. If someone wants to write a
  nice tutorial on how mouse-locations work that would be great.
  */
  let rect = canvas.getBoundingClientRect()

  //account for amount the document scroll bars might be scrolled
  let scrollOffsetX = $(document).scrollLeft()
  let scrollOffsetY = $(document).scrollTop()

  let canX = e.pageX - rect.left - scrollOffsetX
  let canY = e.pageY - rect.top - scrollOffsetY

  return {
    canvasX: canX,
    canvasY: canY
  }

}

function handleMouseDown(e) {

  let canvasMouseLoc = getCanvasMouseLocation(e)
  let canvasX = canvasMouseLoc.canvasX
  let canvasY = canvasMouseLoc.canvasY
  console.log("mouse down:" + canvasX + ", " + canvasY)

  wordBeingMoved = getWordAtLocation(canvasX, canvasY)
  //console.log(wordBeingMoved.word);
  if (wordBeingMoved != null) {
    deltaX = wordBeingMoved.x - canvasX
    deltaY = wordBeingMoved.y - canvasY
    $("#canvas1").mousemove(handleMouseMove)
    $("#canvas1").mouseup(handleMouseUp)

  }

  // Stop propagation of the event and stop any default
  //  browser action

  e.stopPropagation()
  e.preventDefault()

  drawCanvas()
}

function handleMouseMove(e) {

  //console.log("mouse move");

  let canvasMouseLoc = getCanvasMouseLocation(e)
  let canvasX = canvasMouseLoc.canvasX
  let canvasY = canvasMouseLoc.canvasY

  console.log("move: " + canvasX + "," + canvasY)

  wordBeingMoved.x = canvasX + deltaX
  wordBeingMoved.y = canvasY + deltaY

  e.stopPropagation()

  drawCanvas()
}

function handleMouseUp(e) {
  //console.log("mouse up")
  e.stopPropagation()

  //remove mouse move and mouse up handlers but leave mouse down handler
  $("#canvas1").off("mousemove", handleMouseMove) //remove mouse move handler
  $("#canvas1").off("mouseup", handleMouseUp) //remove mouse up handler

  drawCanvas() //redraw the canvas
}


function handleTimer() {
  movingString.x = (movingString.x + 5 * movingString.xDirection)
  movingString.y = (movingString.y + 5 * movingString.yDirection)

  //keep moving string within canvas bounds
  if (movingString.x + movingString.stringWidth > canvas.width) movingString.xDirection = -1
  if (movingString.x < 0) movingString.xDirection = 1
  if (movingString.y > canvas.height) movingString.yDirection = -1
  if (movingString.y - movingString.stringHeight < 0) movingString.yDirection = 1

  drawCanvas()
}

//KEY CODES
//should clean up these hard coded key codes
const ENTER = 13
const RIGHT_ARROW = 39
const LEFT_ARROW = 37
const UP_ARROW = 38
const DOWN_ARROW = 40


function handleKeyDown(e) {

  //console.log("keydown code = " + e.which );
  let keyCode = e.which
  if (keyCode == UP_ARROW | keyCode == DOWN_ARROW) {
    //prevent browser from using these with text input drop downs
    e.stopPropagation()
    e.preventDefault()
  }

}

function handleKeyUp(e) {
  //console.log("key UP: " + e.which);
  if (e.which == RIGHT_ARROW | e.which == LEFT_ARROW | e.which == UP_ARROW | e.which == DOWN_ARROW) {
    //do nothing for now
  }

  if (e.which == ENTER) {
    handleSubmitButton() //treat ENTER key like you would a submit
    $('#userTextField').val('') //clear the user text field
  }

  e.stopPropagation()
  e.preventDefault()

}

function parseChordProFormat(chordProLinesArray) {
  //parse the song lines with embedded chord pro chords into individual movable words

  transposedByNSemitones = 0 //reset transposition in semitones

  //clear any newline or return characters as a precaution --might not be needed
  for (let i = 0; i < chordProLinesArray.length; i++) {
    chordProLinesArray[i] = chordProLinesArray[i].replace(/(\r\n|\n|\r)/gm, "");
  }


  //add the lines of text to html <p> elements
  let textDiv = document.getElementById("text-area")
  textDiv.innerHTML = ''

  for (let i = 0; i < chordProLinesArray.length; i++) {
    let line = chordProLinesArray[i]
    textDiv.innerHTML = textDiv.innerHTML + `<p> ${line}</p>`

    let lyricLine = '' //string representing the lyrics
    let chordWord = '' // string representing the chords
    let insideBrackets = false;
    var skipSpaces = 0 // used to skip the exact no of spaces in lyric line as length of the recent chord

    //separate chords and lyrics by a blank. Preserve the [] characters in chord symbols
    for (let charIndex = 0; charIndex < line.length; charIndex++) {
      let ch = line.charAt(charIndex)
      if (ch == ']') {
        insideBrackets = false;
      } else if (ch == '[') {
        skipSpaces = 0
        insideBrackets = true;
      }
      else if(insideBrackets){
        chordWord += ch
        ++skipSpaces;
      }
       else{
          lyricLine = lyricLine + ch
          if(skipSpaces > 0)
              --skipSpaces;
          else
              chordWord += ' '
        }

    }

    //Now turn lyrics line into individual drag-able words
    //Create Movable Words
    const characterWidth = canvas.getContext('2d').measureText('m').width; //width of one character

    //Make drag-able words
    lyricLine += ' '; //add blank to lyrics line just so it conveniently ends in a blank
    if (lyricLine.trim().length > 0) {

      let theLyricWord = ''
      let theLyricLocationIndex = -1

      for (let j = 0; j < lyricLine.length; j++) {

        let ch = lyricLine.charAt(j)
        if (ch == ' ') {
          //start or end of word or chord symbol
          if (theLyricWord.trim().length > 0) {
            let word = {
              word: theLyricWord,
              //x: posAfterChord +

              x: leftMargin + theLyricLocationIndex * characterWidth  ,
              y: topMargin + i * 2 * lineHeight + lyricLineOffset,
            }
            word.lyric = 'lyric'
            words.push(word)

          }
          theLyricWord = ''
          theLyricLocationIndex = -1

        } else {
          //its part of a lyric word
          theLyricWord += ch
          if (theLyricLocationIndex === -1) theLyricLocationIndex = j
        }
      }
    } //end make lyric words

    chordWord += ' '//add blank to chords line just so it conveniently ends in a blank
    if (chordWord.trim().length > 0) {

      let theChordWord = ''
      let theChordLocationIndex = -1

      for (let j = 0; j < chordWord.length; j++) {

        let ch = chordWord.charAt(j)
        if (ch == ' ') {
          //start or end of word or chord symbol
          if (theChordWord.trim().length > 0) {
            let word = {
              word: theChordWord,
              //x: posAfterChord +

              x: leftMargin + theChordLocationIndex * characterWidth  ,
              y: topMargin + i * 2 * lineHeight + lyricLineOffset - wordHeight ,
            }
            word.chord = 'chord'


            words.push(word)

          }
          theChordWord = ''
          theChordLocationIndex = -1

        } else {
          //its part of a lyric word
          theChordWord += ch
          if (theChordLocationIndex === -1) theChordLocationIndex = j
        }
      }
    }// end of putting chord words

  }
}

function transpose(theWords, semitones) {
  //Transpose any of the chords in the array of word objects theWords by
  //semitones number of musical steps or semi-tones.
  //semitones is expected to be an integer between -12 and +12

  if (semitones === 0) return //nothing to do

  transposedByNSemitones += semitones
  if (transposedByNSemitones >= 12) transposedByNSemitones -= 12
  if (transposedByNSemitones <= -12) transposedByNSemitones += 12

  for (let i = 0; i < words.length; i++) {
    if (words[i].chord) {
      words[i].word = transposeChord(words[i].word, semitones)
    }
  }
}

function transposeChord(aChordString, semitones) {
  console.log(`transposeChord: ${aChordString} by ${semitones}`)
  /*transpose aChordString by semitones
  aChordString is expected to be like: '[Gm7]' or '[F#maj7]'
  Strategy: look for the position of the chord letter name in hard-coded array of
  letter names and if found replace the characters with the ones offset by the argument
  semitones.
  For example to transpose A#m up by three semitones find for A# in RootNamesWithSharps
  array (which would be 1) then replace A# with the name found at RootsNamesWithSharps[1+3]
  which would be C#. Hence A#m transposed up three semitones would be C#m.
  */
  const RootNamesWithSharps = ['A', 'A#', 'B', 'C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#']
  const RootNamesWithFlats = ['A', 'Bb', 'B', 'C', 'Db', 'D', 'Eb', 'E', 'F', 'Gb', 'G', 'Ab']
  let rootNames = RootNamesWithSharps
  let rootNameIndex = -1
  let transposedChordString = ''
  for (let i = 0; i < aChordString.length; i++) {
    if (rootNames.findIndex(function(element) {
        return element === aChordString[i]
      }) === -1) {
      //character is not start of a chord root name (i.e. is not A,B,C,D,E,F, or G)
      if ((aChordString[i] !== '#') && (aChordString[i] !== 'b')) //skip # and b suffix
        transposedChordString += aChordString[i]
    } else {
      //character is start of a chord name root (i.e. A,B,C,D,E,F, or G)
      let indexOfSharp = -1
      let indexOfFlat = -1
      //check to see if we are dealing with names like A# or Bb
      if (i < aChordString.length - 1) {
        indexOfSharp = RootNamesWithSharps.findIndex(function(element) {
          return element === (aChordString[i] + aChordString[i + 1])
        })
        if (indexOfSharp !== -1) transposedChordString += RootNamesWithSharps[(indexOfSharp + 12 + semitones) % 12]
        indexOfFlat = RootNamesWithFlats.findIndex(function(element) {
          return element === (aChordString[i] + aChordString[i + 1])
        })
        if (indexOfFlat !== -1) transposedChordString += RootNamesWithFlats[(indexOfFlat + 12 + semitones) % 12]
      }
      if ((indexOfSharp === -1) && (indexOfFlat === -1)) {
        //chord name is letter without a # or b
        let index = rootNames.findIndex(function(element) {
          return element === aChordString[i]
        })
        if (index !== -1) transposedChordString += rootNames[(index + 12 + semitones) % 12]
      }
    }
  }
  return transposedChordString
}

function handleTransposeUpButton() {
  transpose(words, 1)
  drawCanvas()
}

function handleTransposeDownButton() {
  transpose(words, -1)
  drawCanvas()
}


function handleSaveAsButton(){
    console.log("Save As button pressed -");
    var userText = $('#userTextField').val();
//add the lines of text to html <p> elements

    let chordProLinesArray = handleTextDivision();

    if(userText && userText !=='' && words.length > 0){
      var userRequestObj = {text: 'save'};
      userRequestObj.saveAsFileName = userText;

      userRequestObj.songLines = chordProLinesArray;
      let userRequestJSON = JSON.stringify(userRequestObj);
      //alert ("You typed: " + userText);
      $.post("mySavedSong", userRequestJSON, function(data, status) {
        //console.log("data: " + data)
        //console.log("typeof: " + typeof data)
        let responseObj = data
        movingString.word = responseObj.text
      });
    }
}


function handleRefreshButton(){
    console.log("Refresh button pressed -");
  //add the lines of text to html <p> elements
  handleTextDivision();

}

function handleTextDivision(){
  let textDiv = document.getElementById("text-area")
  textDiv.innerHTML = '';

  let chordProLinesArray = modifiedNewSongLines();
  for (let i = 0; i < chordProLinesArray.length; i++) {

    let line = chordProLinesArray[i]
    console.log(line);
    textDiv.innerHTML +=`<p> ${line}</p>`
  }

  return chordProLinesArray;
}


function modifiedNewSongLines(){

  for(let i=0; i< words.length; i++){
    if(words[i].chord){
      words[i].oldY = words[i].y;
      words[i].y += lyricLineOffset;
    }
  }

  words.sort(sortingTwoWords);

  let arrayOfLines = []
  let currentArrayOfLines = []
  var currentHeight = -1;

  for(let i=0 ; i<words.length; i++){
    if(currentHeight === -1) currentHeight = words[i].y;
    if(Math.abs(words[i].y - currentHeight) < lyricLineOffset){
      words[i].y = currentHeight;
      currentArrayOfLines.push(words[i]);
    }
    else{
      currentHeight = words[i].y;
      arrayOfLines.push(currentArrayOfLines);
      currentArrayOfLines = [];
      currentArrayOfLines.push(words[i]);
    }
  }

  if(currentArrayOfLines.length > 0)
    arrayOfLines.push(currentArrayOfLines);

  currentArrayOfLines = [];
  //console.log('linestosavelength:'+ arrayOfLines.length);

  for(let i=0; i< arrayOfLines.length; i++)
    currentArrayOfLines.push(makeString(arrayOfLines[i]));

    for(let i=0; i< words.length; i++)
      if(words[i].chord)
        words[i].y -= lyricLineOffset;

    return currentArrayOfLines;
}

function makeString(line){

  line.sort(sortingTwoWords);

  let chordsArray = []
  let wordsArray = []

  for(let i=0; i< line.length;i++){
    if(line[i].lyric) wordsArray.push(line[i]);
    if (line[i].chord) chordsArray.push(line[i]);
  }

  if(wordsArray.length === 0){
    let chordString  ='';
    for(let i=0; i< chordsArray.length ; i++){
      chordString += '[' + chordsArray[i].word + '] ';
    }
    return chordString.trim();
  }

  if(chordsArray.length === 0){
    let wordString  ='';
    for(let i=0; i< wordsArray.length ; i++){
      wordString += wordsArray[i].word + ' ';
    }
    return wordString.trim();
  }

  const characterWidth = canvas.getContext('2d').measureText('m').width; //width of one character
  let myXposition = 0;
  let chordWordString = '';

  while(chordsArray.length > 0 && chordsArray[0].x <= wordsArray[0].x){
    chordWordString += '[' + chordsArray[0].word +']';
    chordsArray = removeFirstElementInArray(chordsArray);
  }

  for(let i=0; i< wordsArray.length; i++){

    myXposition = wordsArray[i].x;
    let lyricsLine = wordsArray[i].word;

    for (let charIndex = 0; charIndex < lyricsLine.length; charIndex++){
      let ch = lyricsLine.charAt(charIndex);

      while(chordsArray.length > 0 && chordsArray[0].x <= myXposition){
        chordWordString += '[' + chordsArray[0].word +']';
        chordsArray = removeFirstElementInArray(chordsArray);
      }

      chordWordString += ch;
      myXposition += characterWidth;
    }
    chordWordString += ' ';
    myXposition += characterWidth;
  }

    while(chordsArray.length > 0){
      chordWordString += '[' + chordsArray[0].word +'] ';
      chordsArray = removeFirstElementInArray(chordsArray);
    }

    return chordWordString.trim();
  }

function sortingTwoWords(wordOne,wordTwo){
  if(wordOne.y < wordTwo.y) return -1;
  else if(wordOne.y === wordTwo.y) return 0;
  else return 1;
}

function removeFirstElementInArray(array){
  array.reverse();
  array.pop();
  array.reverse();

  return array;
}


function handleSubmitButton() {

  let userText = $('#userTextField').val() //get text from user text input field
  //clear lines of text in textDiv
  let textDiv = document.getElementById("text-area")
  textDiv.innerHTML = ''

  if (userText && userText !== '') {
    let userRequestObj = {
      text: userText
    }
    let userRequestJSON = JSON.stringify(userRequestObj)
    $('#userTextField').val('') //clear the user text field

    //alert ("You typed: " + userText);
    $.post("fetchSong", userRequestJSON, function(data, status) {
      console.log("data: " + data)
      console.log("typeof: " + typeof data)
      let responseObj = data
      movingString.word = responseObj.text
      words = [] //clear drag-able words array;
      if (responseObj.songLines) parseChordProFormat(responseObj.songLines);
    })
  }

}




$(document).ready(function() {
  //This is called after the broswer has loaded the web page

  //add mouse down listener to our canvas object
  $("#canvas1").mousedown(handleMouseDown)

  //add key handler for the document as a whole, not separate elements.
  $(document).keydown(handleKeyDown)
  $(document).keyup(handleKeyUp)

  timer = setInterval(handleTimer, 100) //animation timer
  //clearTimeout(timer); //to stop timer

  drawCanvas()
})
