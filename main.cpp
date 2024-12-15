#include <iostream>
#include <fstream>   //used to read and write files(ifstream and ofstream)
#include <sstream>   //(stringstream)
#include <windows.h> // provide windows-specific functions like Sleep and system
using namespace std;


// Represents an item with attributes: Item(name), Rate(price per unit), and Quantity(stock available).
class Bill{

    private:
    string Item;
    int Rate, Quantity;

    public:
    Bill():Item(""), Rate(0), Quantity(0){ 
        /*A member initializer list is a part of a constructor that initializes member variables before the constructor's body is executed. 
        It is written with a colon (:) after the constructor name and is followed by a list of initializations, separated by commas.*/
        }


    //setters
    void setItem(string item){
        Item = item;
        }
    
    void setRate(int rate){
        Rate = rate;
        }
    
    void setQuant(int quant){
        Quantity = quant;
        }
    
    
    //getters
    string getItem(){
        return Item;
        }

    int getRate(){
        return Rate;
        }

    int getQuant(){
        return Quantity;
        }

    };

//function
int addItem(Bill b){
    bool close = false;
    while(!close){
        int choice;
        cout<<"\t1.Add."<<endl;
        cout<<"\t2.close."<<endl;
        cout<<"\tEnter Choice: ";
        cin>>choice;
        
        if(choice==1){
            system("cls");

            string item;
            int rate, quant;

            cout<<"\tEnter Item Name: ";
            cin>>item;
            b.setItem(item);

            cout<<"\tEnter Rate Of Item: ";
            cin>>rate;
            b.setRate(rate);

            cout<<"\tEnter Quantity Of Item: ";
            cin>>quant;
            b.setQuant(quant);
            
            //ofstream: This stands for output file stream, which is used to write data to a file.
            //out: The file stream object used to interact with the file.
            //"D:/Bill.txt": The file path where the data will be written. In this case, it is an absolute path on the D: drive.
            //ios::app: This is a mode flag that opens the file in append mode, ensuring that any new data is added at the end of the file without overwriting its current content.
            ofstream out("D:\bill.txt", ios::app);
            if(!out)
            {
                cout<<"\tError: File Can't Open!"<<endl;
            }else
            {
                out<<"\t"<<b.getItem()<<" : "<<b.getRate()<<" : "<<b.getQuant()<<endl<<endl;
            }
            out.close();

            cout<<"\tItem Added Successfuly"<<endl;
            Sleep(3000);
        }
        else if(choice == 2)
        {
            system("cls");
            close = true;
            cout<<"\tBack To Main Menu!"<<endl;
            Sleep(3000);
        }
}
}
int printBill(){
	system("cls");
int count = 0;
bool close = false;
while(!close){
system("cls");
int choice;
cout<<"\t1.Add Bill."<<endl;
cout<<"\t2.Close Session."<<endl;
cout<<"\tEnter Choice: ";
cin>>choice;
if(choice==1){
string item;
int quant;
cout<<"\tEnter Item: ";
cin>>item;
cout<<"\tEnter Quantity: ";
cin>>quant;
ifstream in("D:/Bill.txt");
ofstream out("D:/Bill Temp.txt");
string line;
bool found = false;
while(getline(in, line)){
stringstream ss;
ss<<line;
string itemName;
int itemRate, itemQuant;
char delimiter;
ss>>itemName>>delimiter>>itemRate>>delimiter>>itemQuant;
if(item ==itemName){
found = true;
if(quant <= itemQuant){
int amount = itemRate * quant;
cout<<"\t Item | Rate | Quantity | Amount"<<endl;
cout<<"\t"<<itemName<<"\t "<<itemRate<<"\t "<<quant<<"\t "<<amount<<endl;
int newQuant = itemQuant - quant;
itemQuant = newQuant;
count +=amount;
out<<"\t"<<itemName<<" : "<<itemRate<<" : "<<itemQuant<<endl;
}
else{
cout<<"\tSorry, "<<item<<" Ended!"<<endl;
}
}
else{
out<<line<<endl;
}	
}
if(!found){
cout<<"\tItem Not Available!"<<endl;
}
out.close();
in.close();
remove("D:/Bill.txt");
rename("D:/Bill Temp.txt", "D:/Bill.txt");
}
else if(choice ==2){
close = true;
cout<<"\tCounting Total Bill"<<endl;
}
Sleep(3000);
}
system("cls");
cout<<endl<<endl;
cout<<"\t Total Bill ----------------- : "<<count<<endl<<endl;
cout<<"\tThanks For Shopping!"<<endl;
Sleep(5000);
}
int main(){
Bill b;
bool exit = false;
while(!exit){
system("cls");
int val;
cout<<"\tWelcome To Super Market Billing System"<<endl;
cout<<"\t**************************************"<<endl;
cout<<"\t\t1.Add Item."<<endl;
cout<<"\t\t2.Print Bill."<<endl;
cout<<"\t\t3.Exit."<<endl;
cout<<"\t\tEnter Choice: ";
cin>>val;
if(val==1){
system("cls");
addItem(b);	
Sleep(3000);
}
else if(val==2){
printBill();
}
else if(val==3){
	system("cls");
exit = true;
cout<<"\tGood Luck!"<<endl;
Sleep(3000);
}	
}
}