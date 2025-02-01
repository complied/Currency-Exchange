This program is a Currency exchange program written in the language c++. It first converts the given user amount to USD then later on converts it into the desired currency. It is using Classes to store a lot of functions in one and also has a special promotion feature. 

It Uses a Class to Keep Things Organized
Instead of throwing everything into main(), the program has a CurrencyConverter class that handles all the work. This makes it easier to read and change later.
It Lets You Temporarily Change Exchange Rates
The program allows you to apply a special exchange rate (like a Black Friday deal) without messing up the actual rates. It does this using const_cast, which lets you update "unchangeable" values just for that moment.

