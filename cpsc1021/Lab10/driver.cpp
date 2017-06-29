/* driver.cpp
 * Christopher Brant
 * cbrant
 * Jay Cox
 * jay4
 * Lab 10
 * Lab Section 002
 * Lauren Fuller
 */
/* Driver for lab  files */

#include "Package.h"
#include "ThreeDay.h"
#include "OvernightPackage.h"
#include "Person.h"
using namespace std;

#include <iostream>
#include <iomanip>

/*You will need to write the implementation for the following functions.  */

void getSenderInfo(Person &);
void getRecipientInfo(Person &);
void calculateAndPrint(Package &, ThreeDay&, OvernightPackage&);
void getPackageInfo(double&, double&, double&, double&, double&);


int main()
{
    double w, cost, fee1, fee2, flat;

    Person s;
    Person r;
    getSenderInfo(s);
    getRecipientInfo(r);
    getPackageInfo(w, cost, fee1, fee2, flat);

    // create the package objects
    Package p1(s, r, w, cost);
    ThreeDay p2(s, r, w, cost, fee1);
    OvernightPackage p3(s, r, w, cost, fee2, flat);

    calculateAndPrint(p1, p2, p3);

}

/*This function is used to request and receive information from the user
 *The information received from this function will be used to instantiate the
 *instances of Package, ThreeDay, and OvernightPackage in the main.  See
 *the sample output in the lab specification document for an example.*/

void getPackageInfo(double& w, double& cost, double& fee1, double& fee2,
                    double& flat)
{
    cout << endl << "Enter the weight, in oz, of the package: ";
    cin >> w;

    cout << "Enter the cost per oz, in dollars, of the package: ";
    cin >> cost;

    cout << "Enter the additional fee per ounce of the 3-day package: ";
    cin >> fee1;

    cout << "Enter the additional fee per ounce of the overnight package: ";
    cin >> fee2;

    cout << "Enter the flat fee for the overnight package: ";
    cin >> flat;
}

/*This function is used to request and receive information from the user.
 *The information is used to set the values of a person that will be
 *passed to the instances of Package, ThreeDay, and OverrnightPackage.
 *It represents the "sender" of the Package class.*/

void getSenderInfo(Person& sender)
{
    string temp;    // Temporary string variable to save input
    int z;          // Temporary int for saving zip code

    cout << endl << "Enter the Sender's Name: ";
    getline(cin, temp);
    sender.setName(temp);

    cout << "Enter the Sender's Street Address: ";
    getline(cin, temp);
    sender.setAddress(temp);

    cout << "Enter the Sender's City: ";
    getline(cin, temp);
    sender.setCity(temp);

    cout << "Enter the Sender's State: ";
    getline(cin, temp);
    sender.setState(temp);

    cout << "Enter the Sender's Zip Code: ";
    cin >> z;
    sender.setZip(z);

    // Ignores last of line so that recipient reading works
    cin.ignore();
}

/*Similar to the getSenderInfo function
 *This function is used to request and receive information from the user.
 *The information is used to set the values of a person that will be
 *passed to the instances of Package, ThreeDay, and OverrnightPackage.
 *It represents the "recipient" of the Package class.*/

void getRecipientInfo(Person& recipient)
{
    string temp;    // Temporary string variable to save input
    int z;          // Temporary int for saving zip code

    cout << endl << "Enter the Recipient's Name: ";
    getline(cin, temp);
    recipient.setName(temp);

    cout << "Enter the Recipient's Street Address: ";
    getline(cin, temp);
    recipient.setAddress(temp);

    cout << "Enter the Recipient's City: ";
    getline(cin, temp);
    recipient.setCity(temp);

    cout << "Enter the Recipient's State: ";
    getline(cin, temp);
    recipient.setState(temp);

    cout << "Enter the Recipient's Zip Code: ";
    cin >> z;
    recipient.setZip(z);
}

/*The above functions set the information for the sender and recipient
 *and was passed to the constructors of p1, p2, and p3.  In this
 *function you will use the instance of Package to get the sender
 *and recipient information then call printSenderInfo and
 *printRecipientInfo. */

void calculateAndPrint(Package& p1, ThreeDay& p2, OvernightPackage& p3)
{

    /*create an instance of Person and make it equal to the P1's sender
    *information.  Do the same with P1's recipient.  */
    Person send1 = p1.getSender();
    Person recip1 = p1.getRecipient();

    /*print the sender information*/
    send1.printSenderInfo();

    /*print the recipient information*/
    recip1.printRecipientInfo();

    /*Since we are dealing with money make sure you set the precision to 2
    *and make sure sure trailing zeros are printed.*/
    //cout << fixed << setprecision(2) << showpoint;

    /*Now you are to calculate and print the cost of the Package, ThreeDay,
    *and OvernightPackage  See the sample output.  */

    double packCost = p1.calculateCost();
    double threeDayCost = p2.calculateCost();
    double overnightCost = p3.calculateCost();

    cout << fixed << setprecision(2) << showpoint << endl
         << "Cost calculation for Package: $" << packCost << endl
         << "Cost calculation for ThreeDay: $" << threeDayCost << endl
         << "Cost calculation for Overnight: $" << overnightCost
         << endl << endl;
}
