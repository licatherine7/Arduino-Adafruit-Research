//void propagate(int matrix[][9]);
int rows;
int cols;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
}

void loop() {
  int myPins[8][9];
  propagate(myPins[8][9]);
  delay(2000);
  //topNeighbor(myPins[8][9]);

}

void propagate(int matrix[][9]) {
  int iTemp;
  int val;
  val = 0;
  for (rows = 0; rows < 8; rows++)
  {
    for (cols = 0; cols < 9; cols++)
      {
        if ((rows == 4) && (cols == 4)) { 
          matrix[rows][cols] = 1;
          Serial.println(rows);
        } else {
          matrix[rows][cols] = 0;
        }
        Serial.print(matrix[rows][cols]);
        Serial.print("\t");
      }
    Serial.println();
    Serial.println();
  }
  Serial.println();
  Serial.println();
  Serial.println();
  delay(2000);
}

void topNeighbor(int matrix[][9]) {
  for (rows = 0; rows < 8; rows++)
  {
    for (cols = 0; cols < 9; cols++)
      {
        if (matrix[rows][cols] == 1) { 
          matrix[rows - 1][cols] = 1;
        }
        Serial.print(matrix[rows][cols]);
        Serial.print("\t");
      }
      Serial.println();
      Serial.println();
  }
  Serial.print("text");
}

