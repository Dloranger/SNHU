/****************************************************************************************
 * Author: D. Loranger
 * Date: 12-Nov-2024
 * Purpose: This is an exercise to develop skills using classes, this is the first fully
 * independently developed exercise for this purpose
 * 
 * Course: CS-210
 ****************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

#include "ItemToPurchase.h"
int itemCounter =1;

vector<ItemToPurchase *> ItemList;

int GetExtendedCost(ItemToPurchase * Item) {
   return Item->GetQuantity() * Item->GetPrice();
}

void RequestItemDetails(ItemToPurchase * Item) {
   string name;
   int price;
   int quantity;
   
   cout << "Item "<< itemCounter<<endl;
   itemCounter++;
   cout << "Enter the item name:" << endl;
   getline(cin, name);
   cout << "Enter the item price:"<<endl;
   cin >> price;
   cout << "Enter the item quantity:" <<endl;
   cin >> quantity;
   cin.ignore();
   
   Item->SetName(name); 
   Item->SetPrice(price); 
   Item->SetQuantity(quantity); 
   cout <<endl;

}

/****************************************************************************************
*This is a simplified main() that only requests 2 items per the requirements.
* The code implemented is optimized into a vector with the intent of it being expandable
* into something more useful later on.
****************************************************************************************/
int main() {
   
   ItemList.push_back(new ItemToPurchase); // create new object using default constructor
   RequestItemDetails(ItemList[ItemList.size()-1]); // gather userful details from user
   ItemList.push_back(new ItemToPurchase); // create new object using default constructor
   RequestItemDetails(ItemList[ItemList.size()-1]); // gather userful details from user
   
   int total=0;
   cout <<"TOTAL COST" << endl;
   for (int i=0; i < ItemList.size();++i) {
      cout <<ItemList[i]->GetName() << " " << ItemList[i]->GetQuantity() << " @ $" << ItemList[i]->GetPrice() <<" = $" << GetExtendedCost(ItemList[i])  << endl;
      total += GetExtendedCost(ItemList[i]);
   }
   cout <<endl;
   
   cout <<"Total: $" << total<<endl;
   return 0;
}