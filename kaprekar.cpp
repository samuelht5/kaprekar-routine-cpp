//Proyecto Primer Parcial
//Ricardo Villarreal
//Samuel Holguin
//15/09/2026
//Materia: ADA
//Fuente: CPP Reference
#include<iostream>
using namespace std;

#include<unordered_set>
#include <algorithm>
#include <string>

//Input: a variable string which is our validated input to sort it from max to min.
//Ouput: The sorted input. Example: 3214 -> 4321 in type int
//Importance: We have to make this function so that with the help of the sortMin function, the substraction can be possible and with that, advance on the iterations towards the kaprika number.
//Pre-conditions: It doesnt have any restrictions on the function but on the main() we validate that the input number can only be a 4 digit number and it can only have whole digits, it also cannot have 4 repeated whole numbers.
int sortMax(string P1, bool printval = false){
    int arr[4];
    for(int i=0; i<P1.length(); i++){
        string str(1, P1[i]); 
        arr[i] = stoi(str);//we use the basic string constructor to convert first the char in P1[i] to a string so that it can then be converted into a int with the function stoi. 
    }
    sort(arr, arr+P1.length(), greater<int>()); //the sort function has a time complexity of O(n*log(n)) and it requires as input the initial and final value of the array you want to sort, according to cpp reference, to make it so that it sorts it from max to min on a integer array, we write at the end "greater<int>()"
    int num =0;
    for(int i =0; i<P1.length(); i++){//Convertion to integer
	num = num * 10 + arr[i];//for every digit, it goes through num which is declared as 0, then it multiplies it by ten and adds the element of the array, it repeats for all 4 digits, it keeps "moving the nuber to the left", so it goes like [5, 4, 3, 2] num=0*10+5   num=5*10+4 num=54*10+3 num=543*10+2 num=5432
    }

    if (printval) {//Loop for printing number
        for(int i=0; i<P1.length(); i++){//prints number digit by digit 
            cout << arr[i];
        }
    }
    return num;//Function returns number
}

//Input: a variable string which is our validated input to sort it from min to max.
//Ouput: The sorted input. Example: 3214 -> 1234 in type int
//Importance: We have to make this function so that with the help of the sortMax function, the substraction can be possible and with that, advance on the iterations towards the kaprika number.
//Pre-conditions: It doesnt have any restrictions on the function but on the main() we validate that the input number can only be a 4 digit number and it can only have whole digits, it also cannot have 4 repeated whole numbers.
int sortMin(string P1, bool printval = false){
    int arr[4];
    for(int i=0; i<P1.length(); i++){
        string str(1, P1[i]);
        arr[i] = stoi(str); //same logic as the sortMax
    }
    sort(arr, arr+P1.length());//basic use of the sort function without the greater<int> because it sorts the array from min to max by default.
    int num =0;
    for(int i =0; i<P1.length(); i++){
        num = num * 10 + arr[i];//for every digit it goes through number which is declared as 0, then it multiplies it by ten and adds the element of the array, it repeats for all 4 digits, it keeps "moving the nuber to the left", so it goes like [2, 3, 4, 5] num=0*10+2   num=2*10+3 num=23*10+4 num=234*10+5 num=2345

    }

    if (printval) {//loop for printing number element by element
        for(int i=0; i<P1.length(); i++){//prints number digit by digit
            cout << arr[i];
        }
    }
    return num;//function returns number
}

//Input: None
//Ouput: The max iteration from numbers 0000 to 9999 -> 7 in type int
//Importance: This function is required to display the maximum number of iterations that have to take place in order to take any 4 digit number and apply the substractions and finish on kaprika constant.
//Pre-conditions: It validates that whenever it the substraction returns a number that has less than 4 digits, it adds the 0's necessary to make it a 4 digit number and so the substraction doesn't crashit also checks that the number is not 4 repeated whole numbers and on the main() we validate that the input number can only be a 4 digit number and it can only have whole digits.
int maxIter(){
    int max = 0;//Init for maximum iterations

    for(int i = 0; i <= 9999; i++){//Code will travel from 0000 to 9999, loop will have no input, as an output there will be the number with highest iterations with the number of iterations needed, importance of this loop lies on its capacity to determine which number is the one that needs the most substractions to get to Kaprekar number 
        string val = to_string(i);//For the purpose of presentation i (or turn)is turned into string
        while(val.length() < 4){//if string is of length less than 4
            val = "0" + val; //it keep adding 0s until it does
        }

        if(val[0]==val[1] && val[1]==val[2] && val[2]==val[3]) {
            continue;//We dont include in the loop values whose 4 digits are the same, because it would break the program
        }

        int count = 0;//initialization of counted iterations
		      //Kaprekar process (explained below) 
        while(val != "6174"){   
            int numMax = sortMax(val);//sort values
            int numMin = sortMin(val);

            int diff = numMax - numMin;//substraction of values
            val = to_string(diff);//presentation

            while(val.length() < 4){
                val = "0" + val;
            }
            count++;
        }

        if(count >= max){//If counted iterations are bigger than out registered max iterations
            max = count; //we update the new maximum of iterations
                   }
    }
    return max;
}

int main(){
    //values init
    int resta = 0;
    int iter = 0;
    unordered_set<char> stopnum = {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
    };
    string input;
    bool valid = false;

    do{
        cout << "Input your 4 digit number: ";
        cin >> input;
        if(input.length()==4){ //first we check the size of the input, if its the correct one, we change the value of "valid" to true
            valid = true;
        }
        if (valid &&(input[0]==input[1]&&input[1]==input[2]&&input[2]==input[3])){
		    valid = false;
	    }
        for(char c:input){
            if(stopnum.find(c) == stopnum.end()){ //unordered sets works with a hash number being assigned to every element on the set, which are our numbers from 0 to 9. By comparing the hash of an element we are trying to find to the hash at the end of the table, we can know that, if they are the same, the element we are looking for is not on our unordered_set, and so we change the value of "valid" to false.
                valid = false;
                break; //we add a break because it only takes one invalid char of our input to determine that it should not be accepted.
            }
        }
        if(valid == false){
            cout << "Error, only whole digits ranging from 0 to 9 and 4 digits numbers are allowed. Numbers which have 4 repeated digits aren't allowed either. Please try again: ";
        }
    } while(valid == false);//end of our input validation

   //Loop receives 4 digit value as input, as an output it keeps showing the user sorted numbers and their substractions, at the end iterations needed are shown. Importance of this loop lies on it capability to give us results on Kaprekar process on 4 digit numbers
   int times = 1;
   string input_aux = input;
    while (input != "6174") {//While value isnt yet 6174
        //printed operations
	cout << endl<<"Substraction number "<<times<<": ";
	int numMax = sortMax(input, true);
        cout << "-"; 
        int numMin = sortMin(input, true);

        resta = numMax - numMin;//process of substraction
        cout<<endl;
        cout <<"New value: "<<resta << endl;//printing substraction

        input = to_string(resta);//presentation

        while (input.length() < 4) {
            input = "0" + input;
        }
        iter++;//As long as the loop keeps on, registered iterations will be icreased
	times++;
    }
    cout << endl<< "Substractions needed to go from " << input_aux <<" to 6174: "<< iter<< " out of 7 possibles."<<endl;

    cout << endl;
    cout << "----------------------------------------------------------------------------";
    cout << endl;
    cout << endl;
    cout << "Max iterations for numbers between 0000 to 9999: "<< maxIter() << endl << endl;
    return 0;
}

//Time complexity: O(1) because our inputs are restricted to have only 4 digits, the other for cycle to find the iterations for a given number runs for a maximum of 7 times because that is the max iterations possible and the biggest for cycle is the one which runs from 0000 to 9999, but that is still a constant complexity.
//Space complexity: O(1)
//We give our word that we have carried out this activity with academic integrity.