#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct Book{
	string tittle;
	string author;
	string ISBN;
	bool available;
		
	
};
struct Borrower{
	string name;
	string id;
	vector<Book>borrowedBooks;
	
};

void addBook(vector<Book>&bookDB);
void searchBook(const vector<Book>&bookDB);
void checkoutBook(vector<Book>&bookDB,vector<Borrower>&borrowerDB);
void returnBook(vector<Book>&bookDB,vector<Borrower>&borrowerDB);
void calculateFine(const vector<Borrower>&borrowerDB);
void displayMenu();

int main()
{
	vector<Book>bookDB;
	vector<Borrower>borrowerDB;
	
	while(true){
		displayMenu();
		int choice;
		cin>>choice;
		switch(choice){
			case 1:
				addBook(bookDB);
				break;
				case 2:
				searchBook(bookDB);
				break;
				case 3:
				checkoutBook(bookDB,borrowerDB);
				break;
				case 4:
				returnBook(bookDB,borrowerDB);
				break;
				case 5:
				calculateFine(borrowerDB);
				break;
				case 6:
				return 0;
				default:
					cout<<"Invalid choice.Try again!!"<<"\n";
				
		}
	}
	return 0;
	
}

void addBook(vector<Book>bookDB){
	Book newBook;
	cout<<"Enter book tittle:";
	cin.ignore();
	getline(cin,newBook.tittle);
	cout<<"Enter book ISBN:";
	getline(cin,newBook.ISBN);
	newBook.available=true;
	bookDB.push_back(newBook);
	cout<<"Book added successfully!"<<endl;
	
	
	
}

void searchBook(const vector<Book>&bookDB){
	string searchQuery;
	cout<<"Enter search query(title,author,or ISBN):";
	cin.ignore();
	getline(cin,searchQuery);
	 for(const auto&book:bookDB){
	 	if(book.title.find(searchQuery)!=string::npos||
	 	book.author.find(searcgQuery)!=string::npos||
	 	book.ISBN.find(searcgQuery)!=string::npos)||{
		 cout<<"Book Found!"<<endl;
		  cout<<"Title:"<<book.title<<endl;
		   cout<<"Author:"<<book.author<<endl;
		   cout<<"ISBN:"<<book.ISBN<<endl;
		   cout<<"Availability:"<<(book.available?"Yes":"No")<<endl; 
		   return;
		 }
		 
	 }
	 cout<<"Book not Found!"<<endl;
}

void checkoutBook(vector<Book>&bookDB,vector<Borrower>&borrowerDB){
	string ISBN;
	cout<<"Enter book ISBN:";
	cin.ignore();
	getline(cin,ISBN);
	 for(auto&book:bookDB){
	 	if(book.ISBN==ISBN&&book.available){
	 		string borrowerName;
	 		cout<<"Enter borrower name:"<<endl;
	 		getline(cin,borrowerName);
	 		string borrowerID;
	 		cout<<"Enter borrower ID:"<<endl;
	 		getline(cin,borrowerID);
	 		
	 		Borrower newBorrower;
	 		newBorrower.name=borrowerName;
	 		(link unavailable)=borrowerID;
	 		
	 		newBorrower.borrowedBooks.push_back(book);
	 		
	 		borrowerDB.push_back(newBorrower):
	 			book.available=false;
	 			cout<<"Book checked out successfuly!"<<endl;
	 			return;
	 			
	 		
		 }
	}
	cout<<"Book not available or not found!!";
}
void returnBook(vector<Book>&bookDB,vector<Borrower>&borrowerDB){
	string ISBN;
	cout<<"Enter book ISBN:";
	cin.ignore();
	getline(cin,ISBN);
	 for(auto&borrower:borrowerDB){
	  for(auto&borrower:borrower.borrowerBooks){
	  	if(book.ISBN==ISBN){
	 		book.available;
	 		borrower.borrowerBooks.erase(remove(borrower.borrowerBooks.begin(),borrower.borrowerBooks.end(),book),borrower.borrowerBooks.end());
	 		cout<<"Book returned successfully!"<<endl;
	 		return;
	 	}
	 }
	 		
	  	
	  }	 
	  cout<,"Book not found or not borrowed!!"<<endl;
	  }
	  
	  void calculateFine(const vector<Borrower>&borrowerDB){
	  	cout<<"Fine calculation not implemented yet!"<<endl;
	  
	  }
	  void displayMenu(){
	  	cout<<"Library Management System"<<endl;
	  	cout<<"-------------"<<endl;
	  	cout<<"1.Add Book"<<endl;
	  	cout<<"2.Search Book"<<endl;
	  	cout<<"3.Checkout Book"<<endl;
	  	cout<<"4.Return Book"<<endl;
	  	cout<<"5.CaculateFine Book"<<endl;
	  	
	  }

