#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Fruit class
class Fruit{
private:
        string fruitName;
        float fruitPrice;
        string fruitColour;
    
public:
    //constructor
    Fruit(string fruitName, float fruitPrice, string fruitColour):fruitName(fruitName),fruitPrice(fruitPrice),fruitColour(fruitColour) {
    }
    //setter
        void setFruitName(string FruitName){ fruitName = FruitName; }  
        void setFruitPrice(float FruitPrice){fruitPrice = FruitPrice;}
        void setFruitColour(string FruitColour){fruitColour = FruitColour;}
     //getter
        string getFruitName(){ return fruitName;}
        float getFruitPrice(){return fruitPrice;}
        string getFruitColour(){return fruitColour; }
    
    //Display's Fruits
     void DisplayFruit(){
         cout<<"Fruit: "<<fruitName<<", Price: "<<fruitPrice<<", Colour: "<<fruitColour<<endl;
     }
};

//Customer class
class Customer{
private:
    int custId;
    string custName;
    
public:
    //constructor
    Customer(int custId, string custName):custId(custId),custName(custName)
    {}
    //setter
    void setCustId(int CustId){ custId = CustId;}
    void setCustName(string CustId){custName = CustId;}
    
    //getter
    int getCustId(){return custId;}
    string getCustName(){return custName; }
    
    //Displaying
    void DisplayCust(){
        cout<<"Cust name:"<<custName<<" cust ID: "<<custId<<endl;
             cout<<"======================================="<<endl;
    }
};

//class Order
class Order{
private:
    int customerId;
    float totalPriceOfOrder;
    //itemsOrdered is an object of type vector<Order> which will hold the 
    //fruits and its properties(collection of objects)
    vector<Fruit>itemsOrdered;
    
public :
    //constructor
    Order(int customerId):customerId(customerId),totalPriceOfOrder(0)
    {}
    
    //setter
     void setCustomerId(int CustomerId){ customerId = CustomerId; }
     void setTotalPriceOfOrder(int TotalPriceOfOrder){ 
        totalPriceOfOrder = TotalPriceOfOrder;
    }
    //getter
     int getCustomerId(){ return customerId; }
     float getTotalPriceOfOrder(){ return totalPriceOfOrder; }
    
    //function to add ordered fruits into the list.
    void addOrderedItems(Fruit& OrderedFruit){
        itemsOrdered.push_back(OrderedFruit);
        //here we add the total price of the fruits that ordered by the customer.
        totalPriceOfOrder += OrderedFruit.getFruitPrice();
        
    }    
    
    //displaying the order of the customer with its total price of order.
    void DisplayOrder(){
        cout<<"CustomerId: "<<customerId<<endl;
        
        //iterating the list of order fruits.
        //evaluates to iterator to set of string type automatically
        for(auto &ItemsOrdered : itemsOrdered){
            ItemsOrdered.DisplayFruit();
        }
        cout<<"Totoal priced : "<<totalPriceOfOrder<<endl;
    }
};

//        Funtionality
//---------------------------------//
//function to add fruits in the store
void addFruitInTheStore(vector<Fruit>& addFruit) {
    string fruitName, fruitColour;
    float fruitPrice;
    
    cout << "Enter fruit name , colour, price: ";
    cin >> fruitName>>fruitColour>>fruitPrice;
    
    //fruit will get added into fruit list
    addFruit.push_back(Fruit(fruitName, fruitPrice, fruitColour));
    cout<<"fruit added."<<endl;
}

//function to update fruits in the store
void updateFruitInStore(vector<Fruit>& updateFruit) {
    string fruitNameToUpdate;
    
    cout << "Enter the name of the fruit to update: ";
    cin >> fruitNameToUpdate;
    //iterate in the list to update
    for (auto& updateFruit : updateFruit) {
    //check the match for fruit name
        if (updateFruit.getFruitName() == fruitNameToUpdate) {
            float updatePriceOfFruit;
            string updateColourOfFruit;
            cout << "Enter the price and colour of "<<fruitNameToUpdate<<" to update: ";
            cin >> updatePriceOfFruit>>updateColourOfFruit;
        //to set updated price and colour
            updateFruit.setFruitPrice(updatePriceOfFruit);
            updateFruit.setFruitColour(updateColourOfFruit);
        
            cout << "after update" << endl;
            cout<<"Fruit name: "<<fruitNameToUpdate<<", Price: "<<updatePriceOfFruit<<", colour: "<<updateColourOfFruit<<endl;
            return;
        }
    }
    cout << "Fruit not found!" << endl;
}


//function to delete fruits in the store
void deleteFruitFromStore(vector<Fruit>& fruits) {
    string fruitNameToDelete;
    
    cout << "Enter the name of the fruit to delete: ";
    cin >> fruitNameToDelete;
  //iterating the list of fruits
    for (auto iterate = fruits.begin(); iterate != fruits.end(); iterate++) {
    //check the match for fruit name to delete
        if (iterate->getFruitName() == fruitNameToDelete) {
        //fruit will get deleted
            fruits.erase(iterate);
            cout << "Fruit deleted successfully." << endl;
            return;
        }
    }
    cout << "Fruit not found!" << endl;
}


//function to display fruits in the store
void displayFruitsInStore( vector<Fruit>& displayFruits) {
    for ( auto& displayFruit : displayFruits) {
        displayFruit.DisplayFruit();
    }
}



//function to add cust order fruits in the store
void addOrdersOfTheCustomer(vector<Order>& orders,  vector<Fruit>& fruits) {
    int customerId;
    cout << "Enter customer ID: ";
    cin >> customerId;
    Order order(customerId);
    char choice;
     do {
        string OrderedFruitName;
        cout << "Enter fruit name to add to order: ";
        cin >> OrderedFruitName;
    //flag to confirm whether fruit found or not.
        bool foundFlag = false;
    //loop for to iterate the list of the fruits available in the store.
         for ( auto& iterateFruitListInStore : fruits) {
        //check for the availability of fruit in the store
            if (iterateFruitListInStore.getFruitName() == OrderedFruitName) {
            //  
                order.addOrderedItems(iterateFruitListInStore);
                foundFlag = true;
                break;
            }
        }
        //print msg if friut is not available int he store
         if (!foundFlag) {
            cout << "Fruit not found!" << endl;
        }
    //asking user wheather owner want to add more orders
         cout << "Add more fruits to order? (y/n): ";
        cin >> choice;
    } while (choice == 'y');
    //adding all the ordered list into orders of type vector<Order>
    orders.push_back(order);

    
    
}


//function to display the list of order, ordered by the customer
void displayCustomerOrder( vector<Order>& displayCustomerOrdered) {
    for ( auto& displayCustomerOrder : displayCustomerOrdered) {
        displayCustomerOrder.DisplayOrder();
        
    }
}

//function to search for order for a specific customer ID
void searchOrderByCustomerId( vector<Order>& searchOrder) {
    int customerId;
    cout << "Enter customer ID to search orders: ";
    cin >> customerId;
    
    //iterate the list of customer order
    for ( auto& searchOrder : searchOrder) {
        //check the match for fruit name to delete
        if (searchOrder.getCustomerId() == customerId) {
           //display the orders, ordered by the customer
            searchOrder.DisplayOrder();
            return;
        }
    }
    cout << "Order not found for customer ID: " << customerId << endl;
}





void menuOfFuntionality(){
    cout<<"======================================="<<endl;
        cout << "1. Add Fruit in the store" << endl;
        cout << "2. Update Fruit in the store" << endl;
        cout << "3. Delete Fruit in the store" << endl;
        cout << "4. Display All Fruits in the store" << endl;
        cout << "5. Add Customer's Order " << endl;
        cout << "6. Display Customer's Order" << endl;
        cout << "7. Search Order by Customer ID" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        
}

int main(){
     vector<Fruit> fruit;
     vector<Order> order;
    
    int choice;
    do{
        //to print the list of functionalities
        menuOfFuntionality();
        //take choice from user 
        cin>>choice;
        //switch case to call the functions as per choice
        switch(choice){
            case 1: addFruitInTheStore(fruit);
                    break; 
                    
            case 2:updateFruitInStore(fruit);
                break;
            case 3: deleteFruitFromStore(fruit);
                break;
            case 4: displayFruitsInStore(fruit);
                break;
            
            case 5: addOrdersOfTheCustomer(order,fruit);
                    break; 
                    
            case 6:displayCustomerOrder(order);
                break;
            case 7: searchOrderByCustomerId(order);
                break;
            case 8:
                break;
            
            default:cout<<"enter vaild choice as per the MENU list"<<endl;
                break;
            
        }
    }while(choice != 8);

    return 0;
}


