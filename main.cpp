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

// 1$ USD to other currencies (set as const to prevent unintended modifications)
static const double USD = 1.0;
static const double EUR = 0.96;
static const double GBP = 0.80;
static const double JPY = 154.0;

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
            return 1; // this is for for error handling
        }
    }

    void applyNewPromo(double changedRate, string currency) {
        if (changedRate <= 0) {
            cout << "Your Promotion Rate is less than or equal to 0, Please add something thats more than 0 thanks! ." << endl;
            return; // this is for error handling
        }

    
        // Using `const_cast` to temerarely change their values for a promo
        if (currency == "EUR") *const_cast<double*>(&EUR) = changedRate; //Breaking const  for this function
        else if (currency == "GBP") *const_cast<double*>(&GBP) = changedRate; // Used only when custom promo is applied
        else if (currency == "JPY") *const_cast<double*>(&JPY) = changedRate; // Special offers like Black Friday (example from the assingment)
        else {
            cout << "You Probably have miss spelt or used a different cunrency, Please use one from the list thank you!" << endl;
            return; //this is for error handling
        }

        cout << "Promotional rate now has been uploaded and applied for " << currency << " , The new rate is " << changedRate << endl;
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

        // Fixed point notation with two decimal places for precise currency display
        cout << fixed << setprecision(2);

        cout << "After adding the promotional rate, your Converted Amount is: " << changedAmount << " " << curr2 << endl;
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
    if (curr2 != "USD" && curr2 != "EUR" && curr2 != "GBP" && curr2 != "JPY") { //does not run if the user enters usd, eur, gbp, or jpy in lower case
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

        // Using `cin.fail()` to check for invalid numeric input
        if (cin.fail() || changedRate <= 0) {
            cout << "This is not a possible rate! Please enter a valid Numer, thank you! " << endl;
            return 0;
        }

        converter.applyNewPromo(changedRate, curr1); //promotion gets applied here 
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
Would you like to apply a promotional rate for better prices? (yes/no): yes
Enter new promotional rate for USD: 0.75
After adding the promotional rate, your Converted Amount is: 9.60 GBP
Program ended with exit code: 0
*/
