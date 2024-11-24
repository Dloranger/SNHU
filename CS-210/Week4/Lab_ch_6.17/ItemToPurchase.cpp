#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

   // default constructor
   ItemToPurchase::ItemToPurchase() {
      itemName = "none";      // initialized per problem definition
      itemPrice = 0;          // initialized per problem definition
      itemQuantity = 0;       // initialized per problem definition
   }
   
   // set object name parameter
   void   ItemToPurchase::SetName(string name){
      itemName = name;
      }
   // retrieve object name parameter
   string ItemToPurchase::GetName() const {
      return itemName;
      }
   // set object price parameter   
   void   ItemToPurchase::SetPrice(int price) {
      itemPrice = price;
      }
   // retrieve object price parameter
   int    ItemToPurchase::GetPrice() const {
      return itemPrice;
      }
   // set object quantity parameter
   void   ItemToPurchase::SetQuantity(int quantity) {
      itemQuantity = quantity;
      }
   // retrieve object Quantity parameter
   int    ItemToPurchase::GetQuantity() const {
      return itemQuantity;
      } 

