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
/*int main()
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
}*/
int main(){
	char answer[100];
	subtract(1, 3, 10, 2, 6, 7, answer, 100);
	cout << answer << endl;
	getchar();
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
	}
	for (int i = 1; mantissaResult[i] != '\0' || result[j] != '\0'; i++, j++){
		result[j] = mantissaResult[i];
	}







	/*

	The code contained in this block is not workable code
	//assuming that d is a multiple of 10


	int dmult = d1 / d2;
	int d;
	int nconvert;
	if (dmult > 1){//if d1 is bigger than d2
	n2 = n2*dmult;
	d2 = d1;
	d = d1;
	}
	else{
	n1 = n1 * dmult;
	d1 = d2;
	d = d2;
	}
	int n = n1 - n2;

	// new number is c + n/d
	//now to convert that to a

	return true;
	*/

}
bool tempDivide(int n, int d, char divResult[]){
	float f = float(n / d);
	sprintf(divResult,"%f", f);
}
//--
bool multiply(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len)
{
    //replace this code with your function
    return false;
}
//--
bool divide(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len)
{
    //replace this code with your function
    return false;
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