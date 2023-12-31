#include <iostream>
#include <string>
#include <vector>
#include <iomanip>


template <typename T> class Item
{
public:
    T name;
    T expiration;
    T category;
    int quantity;
    Item(T n, T e, T c, int q)
    {
        name = n;
        expiration = e;
        category = c;
        quantity = q;
    }
};
template <typename T> class Inventory
{
public:

    std::vector<Item<T>> items;

    void addNewItem(Item<T> &obj)
    {
        for (int i = 0; i < items.size(); i++)
        {
            if (items[i].name == obj.name)
            {
                std::cout << "Item is already present in inventory." << std::endl;
            }
        }
         items.push_back(obj);
    }

    int increaseQuantity(T itemname, int quantityadded) 
    {
		  for (size_t i = 0; i < items.size(); i++) 
    {
			 if (items[i].name == itemname)
      { 
		  	items[i].quantity += quantityadded;
			}
		}
        return 0;
	}

    void updateItem(T itemname, T expiration, T category, int quantity) 
    {

        bool itemex = false;
        for (int i = 0; i < items.size(); i++)
        {
            if (items[i].name == itemname)
            {
                items[i].expiration = expiration;
                items[i].category = category; 
                items[i].quantity = quantity;
                itemex = true;
            }
        } 
        if (itemex == false)
            throw ("\nItem is not found.");
    }

    void removeItem(std::string itemname) 
    {

        bool itemex = false;

        for (size_t i = 0; i < items.size(); i++)
        {
            if (items[i].name == itemname)
            {
                items.erase(items.begin() + i);
                itemex = true; 
            }
        }
        if(itemex == false)
            throw ("\nItem is not found.");
    }

    void searchItem(T itemname) 
    {
         for (int i = 0; i < items.size(); i++)
        {
           if (items[i].name == itemname)
           {
            std::cout << "\nItem Name: " << items[i].name << std::endl << "Expiration date: " << items[i].expiration << std::endl << "Category: " << items[i].category << std::endl << "Quantity: " << items[i].quantity << std::endl;
           }
        } 
    }

    int Total()
    {
        std::cout << std::endl << "Total number of items -> " << items.size();
            return items.size();
    }

    void displayItems()
    {
        std::cout << "-------Inventory-------" << std::endl;
        std::cout << std::left << std::setw(20) << "Name" << std::setw(15) << "Expiration" << std::setw(15) << "Quantity" << std::setw(10) << "Category" << std::endl;
        for (int i = 0; i < items.size(); i++)
        {
            std::cout << std::left << std::setw(20) << items[i].name << std::setw(15) << items[i].expiration << std::setw(15) << items[i].quantity << std::setw(15) << items[i].category << std::endl;
        }
    }
};


template <typename T>
class Appointment
{
public:
    T c_name;
    T ap_date;
    T ap_time;
    T CWID;
    Appointment(T n, T d, T t, T cw)
    {
        c_name = n;
        ap_date = d;
        ap_time = t;
        CWID = cw;
    }
};

template <typename T> class AppointmentSystem 
{
public:

    std::vector<Appointment<T>> ap;

    void schedule(Appointment<T> &AP)
    {
        for (int i = 0; i < ap.size(); i++)
        {
            if (ap[i].CWID == AP.CWID)
            {
                std::cout << std::endl << "You have already scheduled an appointment." << std::endl;
                return;
            }
        }
        ap.push_back(AP);
    }

    void Total_appointments(T apdate , T aptime)
    {
        int total = 0;
        for (int i = 0; i < ap.size(); i++)
        {
            if (ap[i].ap_date == apdate && ap[i].ap_time == aptime)
            {
                total++;
            }
        }
        std::cout << std::endl << "You have " << total << " appointments at " << aptime << " on " << apdate << std::endl;      
    }

    void removeRecent() 
    {
        ap.pop_back();
    }

 void display()
    {
        std::cout << "-------Appointments-------" << std::endl;
        std::cout << std::left << std::setw(20) << "Name" << std::setw(15) << "Date" << std::setw(15) << "Time" << std::setw(15) << "CWID" << std::endl;
        for (int i = 0; i < ap.size(); i++)
        {
            std::cout << std::left << std::setw(20) << ap[i].c_name << std::setw(15) << ap[i].ap_date << std::setw(15) << ap[i].ap_time << std::setw(15) << ap[i].CWID << std::endl;
        }
    }
};

int main()
{
Inventory<std::string> i1;
    Item<std::string> I1("Protein Bar", "05/09/2023", "Snacks", 4);
    i1.addNewItem(I1);
    Item<std::string> I2("Milk", "05/12/2023", "Regular", 2);
    i1.addNewItem(I2);
    Item<std::string> I3("Cereals","09/12/2023","Snacks",5);
    i1.addNewItem(I3);
    i1.displayItems();
    i1.updateItem("Milk", "09/24/2023", "Regular", 3);
    i1.displayItems();
    i1.increaseQuantity("Cereals",10);
    i1.displayItems();
    try{
    i1.updateItem("Bar","09/12/2023","Snacks",3);
    }
    catch(const char* msg){
    std::cout << msg << std::endl;
    }
    i1.displayItems();
    i1.updateItem("Cereals","09/27/2023","Regular",4);
    i1.displayItems();
    i1.Total(); 
    try {
    i1.removeItem("Bread");
    }
    catch(const char* msg){
    std::cout<<msg<<std::endl;
    } 
    try{
    i1.removeItem("Milk");
    }
    catch(const char* msg){
    std::cout<<msg<<std::endl;
    } 
    i1.displayItems();
    try{
    i1.searchItem("Cerels");
    }
    catch(const char* msg){
    std::cout<<msg<<std::endl;
    }
    Appointment<std::string> a1("John Bob","09/12/2023","9:30AM","889456723");
    Appointment<std::string> a2("Jim Lee","09/12/2023","10:30AM","883476923");
    Appointment<std::string> a3("Chris Lynn","09/12/2023","12:00PM","879455714");
    Appointment<std::string> a4("Arnav Shah","09/12/2023","12:00PM","879459583");
    AppointmentSystem<std::string> s1;
    s1.schedule(a1);
    s1.schedule(a2);
    s1.schedule(a3);
    s1.schedule(a4);
    s1.display();
    s1.Total_appointments("09/12/2023","12:00PM");
    Appointment<std::string> a5("Chris Lynn","09/12/2023","12:00PM","879455714");
    s1.schedule(a4);
    s1.removeRecent();
    s1.display();
}
