# Store

# Project description (Visual Paradigm in C++)

Our code was partially generated using Visual Paradigm. In this application, we gradually added new updates based on the topics discussed during lectures. Our Visual Paradigm file is divided into: Use Case Diagram, Class Diagram, Sequence Diagram, State Machine Diagram, Activity Diagram, Component Diagram, and Deployment Diagram.

Our project concerns an online shopping platform.

## INSTRUCTION

### 1. Start and Action Selection

After launching the program, the `SystemLogowania` class displays the main menu. The user can choose one of four paths:

- Registration as a new customer
- Logging in as a Customer, for an existing user
- Logging in as a Seller, for warehouse/product management
- Browsing as a Guest, without logging in

### 2.1. Registration (`Gosc` / `SystemLogowania` class)

The system asks the user to enter a login, password, e-mail address, and personal data, such as first name, surname, address, and phone number.

Verification: The system checks the `klienci.txt` file to verify whether the login or e-mail address is already taken.

Saving data: If the verification is successful, the user’s data is added to the `klienci.txt` file.

### 2.2. Login (`Klient` / `SystemLogowania` class)

The user enters their login and password. The system searches the `klienci.txt` file.

If the data is correct, a dynamic object of the `Klient` class is created. This class inherits from the `Gosc` class. The system keeps information about the logged-in user throughout the whole session.

### 3. Customer Panel

After logging in, the Customer can browse and search for products. The `Przegladanie_produktow` class allows the user to display the product list from the `produkty.txt` file or search for a specific product by name, checking its price and availability.

### 4. Seller Panel (`Sprzedawca` class)

If the user logs in using data from the `sprzedawcy.txt` file:

- They gain access to database modification methods.
- Adding products: The seller can add a new product to the `produkty.txt` file.
- Modification: The seller can change the price of an existing product or update the stock level, meaning the number of available items.
- Deleting products: The seller can remove a product that is no longer available in the offer.
