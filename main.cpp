#include <iostream>
using namespace std;

void gradingsystem(){

    double a, b, c, d, e, f, g, h, i, result;
    int idnumber;

    cout << "Enter your ID Number: ";
    cin >> idnumber;

    cout << "Enter your Grade in All Subject: ";
    cin >> a >> b >> c >> d >> e >> f >> g >> h >> i;

    result = (a + b + c + d + e + f + g + h + i) / 9;

    switch(idnumber){

    case 2502110:
    cout << " " << endl;
    cout << "------- result -------" << endl;
    cout << "Name: Dale Andrew Santiago" << endl;
    cout << "Program: BSCpE-2" << endl;
    cout << "Gwa: " << result << endl;
    break;
   case 2302426:
   cout << " " << endl;
    cout << "------- result -------" << endl;
   cout << "Name: Michael Angelo Guillermo" << endl;
   cout << "Program: BSCpE-2" << endl;
   cout << "Gwa: " << result << endl;
   break;
   case 2503769:
   cout << " " << endl;
    cout << "------- result -------" << endl;
   cout << "Name: Gabraven Macarubbo" << endl;
   cout << "Program: BSCpE-2" << endl;
   cout << "Gwa: " << result << endl;
   break;
   default:
   cout << "User Not Found" << endl;
   }

    if(result >=90){
        cout << "Grade: A" << endl;
    }
    else if(result >=80){
        cout << "Grade: B " << endl;

    }
    else if(result >=75) {
        cout << "Grade: C" << endl;
    }
    else {
        cout << "Grade: F" << endl;
    }


}

int main(){

    gradingsystem();
    return 0;
}