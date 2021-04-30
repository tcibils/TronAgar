// This has been emptied, as walls will be created by players themselves.
// Logic to update

// This function is to be called at the start of a game, to define which obstacles will be used for that game.
void initializeGameObstacles() {
  
}

// ----------------------------------------------------------------------------------------------------
// -------------------------------------   GENERIC OBSTACLE FUNCTIONS  --------------------------------
// ----------------------------------------------------------------------------------------------------

// Allows to fill the Obstacles matrix with whatever obstacles we want
void defineObstacle(const byte startingLine, const byte startingColumn, const byte horizontalLength, const byte verticalLength, const byte colourChoice) {
  for(byte horizontalIterator = 0; horizontalIterator < horizontalLength; horizontalIterator++) {
    for(byte verticalIterator = 0; verticalIterator < verticalLength; verticalIterator++) {
      Obstacles[startingLine + verticalIterator][startingColumn + horizontalIterator] = colourChoice;
    }
  }
}

// Fully clears the obstacles
void clearObstacles() {
  for(byte horizontalIterator = 0; horizontalIterator < totalDisplayNumberOfRows; horizontalIterator++) {
    for(byte verticalIterator = 0; verticalIterator < totalDisplayNumberOfColumns; verticalIterator++) {
      Obstacles[horizontalIterator][verticalIterator] = Black;
    }
  }
}

// Takes all the obstacle matrix, which contains them all, and fills the LED Matrix with them so that they get displayed
void displayObstacles() {
  // We iterate on all the matrix size
  for(byte horizontalIterator = 0; horizontalIterator < totalDisplayNumberOfRows; horizontalIterator++) {
    for(byte verticalIterator = 0; verticalIterator < totalDisplayNumberOfColumns; verticalIterator++) {
      // If there is nothing on a spot (no player, no apple) (we want to avoid to put a LED to black if we previously already printed somthing there, so we only override potential existing black spaces)
      if(LEDMatrix[horizontalIterator][verticalIterator] == 0) {
        // Then we display the potential obstacle
        LEDMatrix[horizontalIterator][verticalIterator] = Obstacles[horizontalIterator][verticalIterator];
      }
    }
  }  
}
