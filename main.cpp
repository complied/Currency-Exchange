//
//  main.cpp
//  Currency Converter
//
//  Created by Subigya Parajuli on 1/30/25.
//

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// I used classes in here to make it easier, First this program turns asked currency to USD then converts it to Desired currency.


// 1$ USD to other currencies
static double USD = 1.0;
static double EUR = 0.96;
static double GBP = 0.80;
static double JPY = 154.0;

class CurrencyConverter {
    double amount, changedAmount;
    string curr1, curr2;
    
public:
    CurrencyConverter(double amnt, string from, string to) {
        amount = amnt;
        curr1 = from;
        curr2 = to;
        changedAmount = 0.0;
    }

    // Converts any currency to USD
    double toUSD(string currency, double amount) {
        if (currency == "USD") return amount;
        if (currency == "EUR") return amount / EUR;
        if (currency == "GBP") return amount / GBP;
        if (currency == "JPY") return amount / JPY;
        else {
            cout << "Error, Please use the Same currecny from the list" << endl;
            return 1; // this is for error handling
        }
    }

    // Converts USD to any currency
    double fromUSD(string currency, double amount) {
        if (currency == "USD") return amount;
        if (currency == "EUR") return amount * EUR;
        if (currency == "GBP") return amount * GBP;
        if (currency == "JPY") return amount * JPY;
        else {
            cout << "Error, Please use the Same currecny from the list" << endl;
            return 1; // this is for error handling
        }
    }

    void applyNewPromo(double changedRate, string currency) {
        if (changedRate <= 0) {
            cout << "Your Promotion Rate is less than or equal to 0, Please add something thats more than 0 thanks! ." << endl;
            return; //error handling
        }

        if (currency == "USD") {
            cout << "USD exchange rate cannot be changed!" << endl;
            return;
        }
        if (currency == "EUR") EUR = changedRate;
        else if (currency == "GBP") GBP = changedRate;
        else if (currency == "JPY") JPY = changedRate;
        else {
            cout << "You Probably have miss spelt or used a different cunrency, Please use one from the list thank you!" << endl;
            return; //error handling
        }

        cout << "Promotional rate now has been uploaed applied for " << currency << " , The new rate is " << changedRate << endl;
    }

    void convert() {
        if (amount <= 0) {
            cout << "Please enter a positive number! " << endl;
            return;
        }

        double usdAmount = toUSD(curr1, amount);
        if (usdAmount == -1) {
            cout << "Invalid currency entered. Please enter from the list :USD, EUR, GBP, or JPY." << endl;
            return; //checks if the currency is actually positive
        }

        changedAmount = fromUSD(curr2, usdAmount);
        if (changedAmount == -1) {
            cout << "Invalid currency entered. Please enter from the list :USD, EUR, GBP, or JPY."  << endl;
            return;
        }
        cout << fixed << setprecision(2); //for decimals to pop out right after because it wont show the decimals first
        cout << "After adding the promotinal rate, your Converted Amount is: " << changedAmount << " " << curr2 << endl;
    }
};


int main() {
    double amount;
    string curr1, curr2;
    string applyPromo;

    cout << "=====================================" << endl; // made it a bit fancy
    cout << "Welcome to the currency converter!" << endl;
    cout << "=====================================" << endl;
    cout << "Our Available currencies are: USD, EUR, GBP, JPY" << endl;
    cout << "=====================================" << endl;

    cout << "Please enter your first currency: ";
    cin >> curr1;
    if (curr1 != "USD" && curr1 != "EUR" && curr1 != "GBP" && curr1 != "JPY") {
        cout << "Invalid currency. Please restart and enter USD, EUR, GBP, or JPY." << endl;
        return 0;
    }
    cout << "Please enter your second currency: ";
    cin >> curr2;
    if (curr2 != "USD" && curr2 != "EUR" && curr2 != "GBP" && curr2 != "JPY") { //dosent run if usder enters usd or eur or gbp or jpy in lower caps
        cout << "Invalid currency. Please restart and enter USD, EUR, GBP, or JPY." << endl;
        return 0;
    }
    cout << "Please enter the amount you want to convert: ";
    cin >> amount;

    CurrencyConverter converter(amount, curr1, curr2);

    //for promotional rates - Learned this online had to do a lot of research
    cout << "Would you like to apply a promotional rate for better prices? (yes/no): ";
    cin >> applyPromo;

    if (applyPromo == "yes") {
        double changedRate;
        cout << "Enter new promotional rate for " << curr1 << ": ";
        cin >> changedRate;
        if (cin.fail() || changedRate <= 0) { // another error handling, learned this from the C++ wesbite!
            cout << "This is not a possible rate! Please enter a valid Numer, thank you! " << endl;
            return 0;
        }
        converter.applyNewPromo(changedRate, curr1);
    }
    converter.convert();

    return 0;
}

/*
 
 
 =====================================
 Welcome to the currency converter!
 =====================================
 Our Available currencies are: USD, EUR, GBP, JPY
 =====================================
 Please enter your first currency: USD
 Please enter your second currency: GBP
 Please enter the amount you want to convert: 12
 Would you like to apply a promotional rate for better prices? (yes/no): no
 Converted Amount: 9.60 GBP
 Program ended with exit code: 0
 
 */
/*
=====================================
Welcome to the currency converter!
=====================================
Our Available currencies are: USD, EUR, GBP, JPY
=====================================
Please enter your first currency: USD
Please enter your second currency: GBP
Please enter the amount you want to convert: 12
Would you like to apply a promotional rate for better prices? (yes/no): 0.75
 After adding the promotinal rate, your Converted Amount is: 9.60 GBP
Program ended with exit code: 0
*/
