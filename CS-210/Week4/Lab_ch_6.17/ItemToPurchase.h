#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#include <string>
using namespace std;

class ItemToPurchase {
   public:
      ItemToPurchase();                   // default constructor
      void   SetName(string name);        // name mutator
      string GetName() const;             // name retriever
      void   SetPrice(int price);         // price mutator
      int    GetPrice() const;            // price retriever
      void   SetQuantity(int quantity);   // quantity mutator
      int    GetQuantity() const;         // quantity retriever
      
  private: 
  string itemName;// - Initialized in default constructor to "none"
  int itemPrice; // - Initialized in default constructor to 0
  int itemQuantity;// - Initialized in default constructor to 0   
};



#endif