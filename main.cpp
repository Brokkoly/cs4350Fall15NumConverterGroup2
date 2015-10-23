#include <iostream>

using namespace std;

bool characteristic(char numString[], int& c);
bool mantissa(char numString[], int& numerator, int& denominator);
bool add(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len);
bool subtract(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len);
bool multiply(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len);
bool divide(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len);
void intToCString(int input, char outputarray[]);
void reverseCString(char toReverse[], int len);
int cStringLen(char inputArray[]);
int getNumDigits(int num);
int fractionToDecimal(int n, int d, int len);
int main()
{
    //some numbers to work with
    char number1[] = "   123.456";
    char number2[] = "-456  ";
    
    //a place for the answer
    char answer[100];
    
    //intermediate values
    int c1, n1, d1;
    int c2, n2, d2;
    
    //if the conversion from C string to integers can take place
    if(characteristic(number1, c1) && mantissa(number1, n1, d1) &&
       characteristic(number2, c2) && mantissa(number2, n2, d2))
    {
        //do some math with the numbers
        if(add(c1, n1, d1, c2, n2, d2, answer, 100))
        {
            //display string with answer -332.544
            cout<<"The sum of the numbers "<<number1<<" and "<<number2<<" is "<<answer<<endl;
        }
        else
        {
            //display error message
            cout<<"Cannot add the numbers: "<<number1<<" and "<<number2<<endl;
        }
        
        if(subtract(c1, n1, d1, c2, n2, d2, answer, 100))
        {
            //display string with answer 579.456
            cout<<"The difference of the numbers "<<number1<<" and "<<number2<<" is "<<answer<<endl;
        }
        else
        {
            //display error message
            cout<<"Cannot subtract the numbers: "<<number1<<" and "<<number2<<endl;
        }
        
        if(multiply(c1, n1, d1, c2, n2, d2, answer, 100))
        {
            //display string with answer -56295.936
            cout<<"The product of the numbers "<<number1<<" and "<<number2<<" is "<<answer<<endl;
        }
        else
        {
            //display error message
            cout<<"Cannot multiply the numbers: "<<number1<<" and "<<number2<<endl;
        }
        
        if(divide(c1, n1, d1, c2, n2, d2, answer, 100))
        {
            //display string with answer -0.27073684210526
            cout<<"The quotient of the numbers "<<number1<<" and "<<number2<<" is "<<answer<<endl;
        }
        else
        {
            //display error message
            cout<<"Cannot divide the numbers: "<<number1<<" and "<<number2<<endl;
        }
    }
    else
    {
        //handle the error on input
        cout<<"Error converting the strings into numbers: "<<number1<<" and "<<number2<<endl;
    }
    
    return 0;
}

//--
bool characteristic(char numString[], int& c)
{
    //replace this code with your function
    return false;
}
//--
bool mantissa(char numString[], int& numerator, int& denominator)
{
    //replace this code with your function
    return false;
}
//--
bool add(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len)
{
    //replace this code with your function
    return false;
}
//--
bool subtract(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len){
	//Assuming that we are doing number 1 minus number 2
	int c = c1 - c2;
	//Currently waiting to recieve the divide function code, then the subtract function can be implemented.
	//TODO overflow checks. We need to standardize how we do these.
	int tempNumerator1, tempNumerator2, finalDenominator;
	tempNumerator1 = n1*d2;
	tempNumerator2 = n2*d1;
	finalDenominator = d1*d2;
	char cResult[20];
	char mantissaResult[20];
	int n = n1 - n2;
	if (n > finalDenominator){
		c += n / finalDenominator;
		n = n%finalDenominator;
	}
	intToCString(c, cResult);
	int j = 0;
	for (j; (cResult[j] != '\0'||result[j]!='\0'); j++){
		result[j] = cResult[j];
	}
	if (divide(n,0,0,finalDenominator,0,0,mantissaResult,20)){
		//use real division function in final code
		//if this equates to false that means something went wrong and we should throw an error.
		cout << "ERROR in the divide function! Panic!" << endl;
		return false;
	}
	for (int i = 1; mantissaResult[i] != '\0' || result[j] != '\0'; i++, j++){
		result[j] = mantissaResult[i];
	}
	return true;
}
//--
bool multiply(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len)
{
    //replace this code with your function
    return false;
}
//--
bool divide(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len){
	if (d1 == 0 || d2 == 0 || (c2 == 0 && n2 == 0)){
		return false;
	}
	else{
		//get fractions back to "decimal" with part of the number after the decimal saved as int
		int decimal1 = fractionToDecimal(n1, d1, len);
		int decimal2 = fractionToDecimal(n2, d2, len);

		//figure out have many digits the whole numbers will take up in the answer
		int aproximation = c1 / c2;
		int digits = getNumDigits(aproximation);

		//check if answer will be negative
		bool negative = false;
		if (aproximation < 0){
			negative = true;
		}

		//tack on the "c"s to the beginning of the numbers
		int powersOfTen = 1;
		for (int i = 0; i < len; i++){
			powersOfTen = powersOfTen * 10;
		}
		int number1 = c1 * powersOfTen + decimal1;
		int number2 = c2 * powersOfTen + decimal2;

		//divide the two numbers
		int answer = 0;
		int newNum = number1 * 10;
		for (int i = 0; i < len - 2; i++){
			answer = answer * 10;
			int newDigit;
			newDigit = newNum / number2;
			newNum = newNum%number2 * 10;
			answer = answer + newDigit;
		}

		//find number of preceding zeros
		int numDigitsInAnswer = getNumDigits(answer);
		int numZeros = 0;
		if (numDigitsInAnswer < len - 1){
			numZeros = (len - 1) - numDigitsInAnswer;
		}

		//seperate answer integer into it's parts and store it in result array
		int thisNum;
		int thisDigit;
		int runningNum = 0;
		int tens = 1;
		for (int i = 0;i < digits; i++){
			tens *= 10;
		}
		for (int i = 0; i < len - 1; i++){

			if (i == digits){
				result[i] = '.';
				numZeros++;
			}
			else if (numZeros > i){
				result[i] = '0';
			}
			else{
				runningNum = runningNum * 10;
				tens = tens / 10;
				thisNum = answer / tens;
				thisDigit = thisNum - runningNum;
				runningNum = runningNum + thisDigit;
				result[i] = thisDigit + '0';
			}
		}
		result[len - 1] = '\0';

		return true;
	}
}
void intToCString(int input, char outputarray[]){
	bool isNeg = false;
	if (input < 0){
		isNeg = true;
		input = input*-1;
	}
	//function for converting an integer to a Cstring
	int tempInput = input;
	char tempOutputArray[10];//TODO replace 10 with a number that is 1+the order of MAX_int
	char tempArray[10];//TODO replace 10 with a number that is 1+the order of MAX_int
	int numDigits = 0;
	for (int i = 0; i < 10; i++)
	{
		//This is the algorithm in use.
		/*
		152%10=2
		152/10 = 15
		numdigits = 1
		15%10 = 5
		15/10 = 1
		numdigits = 2
		1%10 = 1
		1/10 = 0
		numdigits = 3
		//After this process, tempArray would look like {2,5,1}
		*/
		//TODO make this work if the input is zero
		tempArray[i] = (tempInput % 10) + '0';
		tempInput = tempInput / 10;
		numDigits++;
		if (tempInput == 0){
			break;
		}
	}
	if (isNeg){
		tempArray[numDigits] = '-';
		numDigits++;
	}
	reverseCString(tempArray, numDigits);
	for (int i = 0; i < numDigits; i++){
		outputarray[i] = tempArray[i];
	}
	outputarray[numDigits] = '\0';
}
void reverseCString(char toReverse[], int len){
	//it was necessary to reverse a cstring a few times, so it was put into its own helper function
	char tempOutputArray[100];//TODO use Max_int
	for (int i = 0; i < len; i++){
		tempOutputArray[i] = toReverse[len - 1 - i];
	}
	for (int i = 0; i < len; i++){
		toReverse[i] = tempOutputArray[i];
	}
}
int intStringToInt(char intString[], int len)
{
	//This Function converts a cstring representing an integer to an integer
	int result = 0;
	int mult = 1;
	reverseCString(intString, len);
	for (int i = 0; i < len; i++)
	{
		mult = 1;
		for (int j = 0; j < i; j++){
			mult = mult * 10;
		}
		result += mult*(intString[i] - '0');
	}
	return result;
}

int cStringLen(char inputArray[]){
	//A short helper function to make it easier to work with cStrings
	int len = 0;
	char current = 'd';
	while (current != '\0'){
		if (inputArray[len] != NULL){
			current = inputArray[len];
			len++;
		}
		else{
			break;
		}
	}
	return len;
}
int fractionToDecimal(int n, int d, int len){
	//takes in a numerater and denominator and converts them into a decimal
	int decimal = 0;
	int remander = n * 10;
	int newDigit;
	for (int i = 0; i < len; i++){
		decimal = decimal * 10;
		newDigit = remander / d;
		remander = (remander%d) * 10;
		decimal = decimal + newDigit;
	}
	return decimal;
}
int getNumDigits(int num){
	//returns the number of digits an integer has
	int powersOfTen = 1;
	int numDigits = 0;
	while (powersOfTen <= num){
		powersOfTen *= 10;
		numDigits++;
	}
	if (num == 0){
		numDigits = 1;
	}
	return numDigits;
}