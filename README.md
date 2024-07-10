Prata "C++ Primer Plus", 6th edition

Chapter 13 ("Class Inheritance"), task 3:

Refactoring task: revise the baseDMA-lacksDMA-hasDMA class hierarchy so that all three classes are derived from an ABC.
Test the result with a program similar to the one in Listing 13.10 (usebrass2.cpp - polymorphic example). 
That is, it should feature an array of pointers to the ABC and allow the user to make runtime decisions 
as to what types of objects are created.Add virtual View() methods to the class definitions to handle displaying the data.

Sample user input after line 15 in ...client.cpp:

1: Shirt - firstDerived (label - "Portabelly")

2: Baloon - lacksDMA (label - "Blimpo")

3: Map - hasDMA (style - "Mercator", label - publisher = "Lonely Planet Publications")
