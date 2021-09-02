#include <iostream>

class Car
{
private:
	std::string company;
	std::string model;
public:
	Car(std::string n_company, std::string n_model): company(n_company), model(n_model) {
		std::cout << "Car constructor " << std::endl;
		std::cout << company << " - " << model << std::endl;
	}
	virtual ~Car() {
		std::cout << "Car destructor " << std::endl;
	}
};

class PassengerCar : virtual public Car
{
private:
	std::string company;
	std::string model;
public:
	PassengerCar(std::string n_company, std::string n_model) : Car(n_company, n_model), 
		company(n_company), model(n_model) {
		std::cout << "PassengerCar constructor " << std::endl;
		std::cout << company << " - " << model << std::endl;
	}
	virtual ~PassengerCar() {
		std::cout << "PassengerCar destructor " << std::endl;
	}

};

class Bus : virtual public Car
{
private:
	std::string company;
	std::string model;
public:
	Bus(std::string n_company, std::string n_model): Car(n_company, n_model),
		company(n_company), model(n_model) {
		std::cout << "Bus constructor " << std::endl;
		std::cout << company << " - " << model << std::endl;
	}

	virtual ~Bus(){
		std::cout << "Bus destructor " << std::endl;
	}
};

class Minivan : public PassengerCar, public Bus
{
private:
	std::string company;
	std::string model;
public:
	Minivan(std::string n_company, std::string n_model) :PassengerCar(n_company, n_model),
		Bus(n_company, n_model), Car(n_company, n_model), company(n_company), model(n_model) {
		std::cout << "Minivan constructor " << std::endl;
		std::cout << company << " - " << model << std::endl;
	}

	virtual ~Minivan() {
		std::cout << "Minivan destructor " << std::endl;
	}
};

int main()
{
	Car a("Nissan", "Skilinen");
	PassengerCar b("Nissan", "Passat");
	Bus c("Nissan", "Bus");
	Minivan d("Nissan", "Minivan");

	return 0;
}