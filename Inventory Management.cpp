#include<iostream>
#include<conio.h>
#include<string>
#include<cstring>
using namespace std;

struct enterItems
{
    float unitPrice;
	 int   copies, prodID; 
	 char  name [30];
	 char  business [30];
	 
};

class deptStore
{
public:
		int itemNum;
		enterItems database[200];
		
		deptStore()
			{
				itemNum=0;
			}
			
			void addItem (char itemName [] , char business [], int productID , int c , float p );
			void deleteItem (char itemName [], int productID);
			enterItems* searchItem (char itemName [], int productID);
			void updateItem (char itemName[], int productID, int sum, float price);
			
};

	void deptStore :: addItem(char itemName [], char business [], int productID, int c, float p)
	{
		strcpy (database [itemNum].name, itemName);
		strcpy (database[itemNum].business, business);
		database[itemNum]. prodID = productID;
		database[itemNum].copies = c;
		database[itemNum].unitPrice = p;
		cout << " \n\t\t YOU HAVE SUCCESSFULLY ENTERED THE ITEM! \n";
		itemNum++;		
	}
	
	void deptStore :: deleteItem (char itemName[], int productID)
	{
		int i;
		for ( i = 0 ; i < itemNum ; i++)
			{
				if ((strcmp (itemName, database[i].name) ==0 ) && (database[i].prodID== productID))
				{
					database[i].copies--;
					cout << " \n\t\t YOU HAVE SUCCESSFULLY DELETED THE ITEM ! \n" ;
						return; 				
					}
			}
		cout << " \n \t \t SORRY THE ITEM COULD NOT BE FOUND PLEASE TRY AGAIN \n ";
	}
	
	
	enterItems*deptStore::searchItem (char itemName[], int productID)
{
	int i;
	for (i = 0 ; i < itemNum; i++)
	{
		if ((strcmp( itemName, database[i].name)==0 ) && (database[i].prodID == productID))
		return &database[i];
	}
		return NULL;
		
}		
	
	void deptStore:: updateItem (char itemName[], int productID, int sum, float price)
{
		enterItems *item = searchItem (itemName, productID);
		if (item == NULL)
		{
			cout << "\n\t\t SORRY THE ITEM COULD NOT BE FOUND \n";
			return;
		}
		
		item -> copies+= sum;
		item -> unitPrice = price;
	}	
	
	
	int main()
	{
		deptStore dept;
		char name [30], business[30];
		int prodID, quantity, option; 
		float  unitPrice;
		
		do
		{
			cout << "\n\t\t **************** > > TAYLORS FUN PARTY STORE < <  ******************";
			cout << "\n\t\t\t\t\t |----------MENU----------|";
			cout << "\n\t\t\t		1  Insert Data";
			cout << "\n\t\t\t		2  Delete Data";
			cout << "\n\t\t\t		3  Search Entry";
			cout << "\n\t\t\t		4  Update Entry";
			cout << "\n\t\t\t		5  Exit Inventory System";
			cout << "\n\t\t	Select your choice:   ";
			cin >> option;
			
			switch(option)
			{
				case 1: cin.getline(name, 80); 
						cout<< "\n\t\t\t Please enter the name of your item :  ";
						cin.getline(name, 80);
						cout<<"\n\t\t\t Company /Business:   ";
						cin.getline(business,80);
						cout<<"\n\t\t\t	Enter the product ID:  ";
						cin>>prodID;
						cout<<"\n\t\t\t Enter the quanity of the item:  ";
						cin>>quantity;
						cout<<"\n\t\t\t\t What is price per item:  ";
						cin>>unitPrice;
						dept.addItem(name, business, prodID, quantity, unitPrice);
						break;
						
				case 2: cin.getline(name, 80);
						cout<<"\n\t\t\t Enter the name of the item:  ";
						cin.getline(name, 80);
						cout<<"\n\t\t\t Enter the product ID:  ";
						cin>>prodID;
						dept.deleteItem(name,prodID);
						break;
				case 3: cin.getline(name,80);
						cout << "\n\t\t\t Please enter the name of the product:  ";
						cin.getline(name,80);
						cout<<"\n\t\t\t Enter the product ID: ";
						cin>> prodID;
						enterItems *find;
						find = dept.searchItem(name, prodID);		
						if(find!=NULL)
						{
							cout << "\n\t\t\t\t ||||S||||E|||||A||||R|||||C|||||H|||I|||||N|||G||||||";
							cout << " \n\t\t\t WE FOUND THE ITEM! \n" << "\n\t\t\t Name of the item: " << find-> name << "\n\t\t\t Business / Company : " 
							<< find -> business << "n\t\t\t Product ID : " << find -> prodID <<"\n\t\t\t Total quanitiy available :  " << find->copies << "\n\t\t\t Unit Price of Item: \n\t" << find-> unitPrice;
							
						}
						if(quantity < 15)
						{
							cout << "  WARNING, THIS ITEM WILL BE OUT OF STOCK SOON. CALL MANUFACTUER FOR ORDER BATCH  ";
						}
						
						else 
						cout << "\n\t\t\t Sorry we could not find that item !";
						break;
				case 4: cin.getline(name, 80);
						cout<<"\n\t\t\t Enter the name of the item:  ";
						cin.getline(name, 80);
						cout<<"\n\t\t\t Enter the product ID:  ";
						cin>>prodID;
						cout << "\n\t\t\t Enter the new quanity entry:  ";
						cin >> quantity;
						cout << "\n\t\t\t Enter the updated price of item:  \n\t";
						cin>> unitPrice;
						dept.updateItem(name, prodID, quantity, unitPrice);
						if(quantity < 15)
						{
							cout << "  \n\t\tWARNING, THIS ITEM WILL BE OUT OF STOCK SOON.\n\t\t CALL MANUFACTUER FOR ORDER BATCH  ";
						}
						break;
						
							}
			
			
			
			
		}while (option!=5);
		return 0;
		
		
		
	}
	
	
	
	
	
	
	
	
	
	
	
