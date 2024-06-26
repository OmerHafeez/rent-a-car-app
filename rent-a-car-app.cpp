#include<iostream>

using namespace std;

class RentalReservation
{
    char reservation_ID[8];
    string customer_name;
    string car_make_and_model;
    int pickup_date;
    int return_date;
    int rental_duration;
    int rental_rate;
    int rental_total;

public:
	//setters
    void set_reservation_ID(char id[8]) 
    {
    	for(int i=0;i<8;i++)
        reservation_ID[i]=id[i];
    }
    void set_customer_name(string name)
    {
        customer_name=name;
    }
    void set_car_make_and_model(string make)
    {
        car_make_and_model=make;
    }
    void set_pickup_date(int pdate)
    {
        pickup_date=pdate;
    }
    void set_return_date(int rdate)
    {
        return_date=rdate;
    }
    
    //working
void validateReservationID() const
{
    bool check1 = false;
    bool check2 = false;
    bool check3 = false;
    bool check4 = false;
    int count = 0;
    int sum = 0;
    int length = 0;
    
    // Check if reservation ID is 8 characters long
    for (int i = 0; i < 8; i++)
    {
        if (reservation_ID[i] == '\0')
            length++;
    }
    if (length == 8)
        check1 = true;
    
    // Check if reservation ID has at least 2 non-alphanumeric characters
    for (int i = 0; i < 4; i++)
    {
        if (!isalnum(reservation_ID[i]))
            count++;
    }
    if (count >= 2)
        check2 = true;
    
    // Check if last 4 characters of reservation ID are digits
    if (isdigit(reservation_ID[4]) && isdigit(reservation_ID[5]) &&
        isdigit(reservation_ID[6]) && isdigit(reservation_ID[7]))
        check3 = true;
    
    // Check if the sum of the last 4 digits is greater than 18
    if (check3 == true)
    {
        for (int i = 4; i < 8; i++)
        {
            if (isdigit(reservation_ID[i]))
                sum += reservation_ID[i] - '0'; // Convert from ASCII to integer
        }
    }
    if (sum < 18)
        check4 = true;
    
    // Output error codes if any of the checks fail
    if (check1 == false)
    {
        cout << "Error code 1: Reservation ID must be 8 characters long" << endl;
    }
    if (check2 == false)
    {
        cout << "Error code 2: Reservation ID must contain at least 2 non-alphanumeric characters" << endl;
    }
    if (check3 == false)
    {
        cout << "Error code 3: Last 4 characters of Reservation ID must be digits" << endl;
    }
    if (check4 == false)
    {
        cout << "Error code 4: Sum of last 4 digits of Reservation ID must be less than 18" << endl;
    }
}


	
    
    void validateMakeModel () const
    {
    	if(car_make_and_model=="Suzuki_Mehran")
		cout<<"The car is available"<<endl;
    	else if(car_make_and_model=="Suzuki_Alto")
		cout<<"The car is available"<<endl;
    	else if(car_make_and_model=="Honda_City")
		cout<<"The car is available"<<endl;
		else if(car_make_and_model=="Toyota_corolla")
		cout<<"The car is available"<<endl;
		else if(car_make_and_model=="Toyota_Land_Cruiser")
		cout<<"The car is available"<<endl;
		else if(car_make_and_model=="Audi_A6")
		cout<<"The car is available"<<endl;
		else
		cout<<"The car is not available"<<endl;
	}
	
int calculate_rental_duration() const
{
    int rd = return_date % 100;
    int rm = (return_date / 100) % 100;
    int ry = return_date / 10000;
    int pd = pickup_date % 100;
    int pm = (pickup_date / 100) % 100;
    int py = pickup_date / 10000;
    int rental_duration = 0;

    if (rd >= pd)
    {
        rental_duration = rd - pd;
    }
    else
    {
        rental_duration = (30 - pd) + rd;
        rm--;
    }

    if (rm >= pm)
    {
        rental_duration += (rm - pm) * 30;
    }
    else
    {
        rental_duration += ((12 - pm) + rm) * 30;
        ry--;
    }

    while (ry >= py)
    {
        if ((ry % 4 == 0 && ry % 100 != 0) || ry % 400 == 0)
        {
            rental_duration += 366;
        }
        else
        {
            rental_duration += 365;
        }
        ry--;
    }
	cout<<"rental duration is"<<rental_duration<<endl;
    return rental_duration;
}

	
    int Calculate_rental_rate () 
    {
    	if(car_make_and_model=="Suzuki_Mehran")
    	rental_rate=10;
    	else if(car_make_and_model=="Suzuki_Alto")
		rental_rate=20;
    	else if(car_make_and_model=="Honda_City")
		rental_rate=30;
		else if(car_make_and_model=="Toyota_corolla")
		rental_rate=40;
		else if(car_make_and_model=="Toyota_Land_Cruiser")
		rental_rate=50;
		else if(car_make_and_model=="Audi_A6")
		rental_rate=60;
		else
		rental_rate=0;
		return rental_rate;
	}
	
	int Calculate_rental_total () 
	{
		rental_total=rental_duration*rental_rate;
		return rental_total;
	}
	
	 void print_reservation_details() const 
	 {
        cout << "Reservation ID: " << reservation_ID << endl;
        cout << "Customer Name: " << customer_name << endl;
        cout << "Car Make and Model: " << car_make_and_model << endl;
        cout << "Pickup Date: " << pickup_date << endl;
        cout << "Return Date: " << return_date << endl;
        cout << "Rental Duration: " << rental_duration << " days" << endl;
        cout << "Rental Rate: $" << rental_rate << " per day" << endl;
        cout << "Rental Total: $" << rental_total << endl;
    }
	
  
};

int main ()
{
    RentalReservation customer;
    int pdate, rdate;
    string name,make;
    char id[9];
    cout << "Enter 8 char long reservation ID "<<endl;
    cin.getline(id,9);
    customer.set_reservation_ID(id);
    cout << "Enter name of the customer: "<<endl;
    cin>>name;
    customer.set_customer_name(name);
    cout << "Enter the name of the car make: "<<endl;
    cin>>make;
    customer.set_car_make_and_model(make);
    cout << "Enter date of pickup: "<<endl;
    cin >> pdate;
    customer.set_pickup_date(pdate);
    cout << "Enter date of return: "<<endl;
    cin >> rdate;
    customer.set_return_date(rdate);
	
	customer.validateReservationID();
	customer.validateMakeModel();
    customer.calculate_rental_duration();
	int RentalRate=customer.Calculate_rental_rate();
	int TotalRent=customer.Calculate_rental_total();
	customer.print_reservation_details();
}
