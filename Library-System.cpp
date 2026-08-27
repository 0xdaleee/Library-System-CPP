    #include <iostream>
    using namespace std;

    class LibrarySystem{
        private:
        int add, returnbook, borrow;
        int borrowed = 0;
        int total = 10;
        char choice;
        char option;

        public:
        void displayTitle(){
            cout << endl;
            cout << "---------- Library System ----------" << endl;
            cout << endl;
        }
        void mainFunction(){
            

            do{ 

            cout << "Select an option: " << endl;
            cout << "1. Add Book" << endl;
            cout << "2. Return Book " << endl;
            cout << "3. Total Books " << endl;
            cout << "4. Borrow Book " << endl;
            cout << "5. Exit: " << endl;

            cout << " " << endl;

            cout << "Enter your choice: ";
            cin >> option;

           

            switch(option){
                case '1': {
                cout << "Add Book: ";
                cin >> add;
                cout << endl;
                 total = (add + total);

                  cout << "Add book Successfully " << endl;
                            cout << "Added books: " << add << endl;
                            cout << "Total Books: " << total << endl; 

                cout << endl;
                break;
                }
                case '2': {
                     if (borrowed > 0) {

                        cout << "Return Book: ";
                        cin >> returnbook;
                        cout << " " << endl;

                        if (returnbook <= borrowed) {
                            borrowed = borrowed - returnbook;
                            total = total + returnbook;

                            cout << "Books returned successfully" << endl;
                            cout << "Books Returned : " << returnbook << endl;
                            cout << "Total Books: " << total << endl; 
                            
                        }
                        else {
                            cout << "You cant return more than you borrwed "  << endl;                  
                        }

                    }
                    else {
                        cout << "Borrow a book first, dumbass " << endl;
                          
                    }

                break;
                }
                case '3': {
                    cout << "Total of Books: " << total << endl;
                    break;
                }
                case '4': {
                    cout << "How many books u want to borrow? ";
                    cin >> borrow;
                    cout << " " << endl;

                    if(borrow <= total){
                        total = (total - borrow);
                        borrowed = (borrowed + borrow);

                        cout << "Borrowed Successfully " << endl;
                            cout << "Borrowed books: " << borrowed << endl;
                            cout << "Total Books: " << total << endl; 
                    }
                    else {
                        cout << "NOt enough book" << endl;
                    }
                    break;
                }
                case '5': {
                    cout << " ";
                    break;
                }
                default:
                cout << "Invalid Option " << endl;
            }

            cout << " " << endl;
            if (option != '5') {
    cout << "Would u like to add another transaction (y/n)? ";
            cin >> choice;
}
            

            } while ((choice == 'y' || choice == 'Y') && option != '5');
            cout << "Thank You" << endl; 
            
           
        }
};


int main(){

    LibrarySystem obj;
    obj.displayTitle();
    obj.mainFunction();
    return 0;
}
//ADT Name: Library System
//Problem: Managing books borrowed, returned, and total books in a library system.
//Data: Returned books, borrowed books, total books, user choices for operations.
//Operations: Add Book, Return Book, Total Books, Borrow Book, Exit.