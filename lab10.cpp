#include <iostream>
#include <vector>

class Component
{
private:
	unsigned int c_id;
	std::string c_name;
	unsigned int c_price;

public:
	Component(unsigned int id, std::string name, unsigned int price)
	{
		c_id = id;
		c_name = name;
		c_price = price;
	}

	std::string Name()
	{
		return c_name;
	}

	unsigned int C_Price()
	{
		return c_price;
	}
};

class Machine
{
private:
	unsigned int m_id;
	std::string m_name;
	unsigned int m_price = 0;
	std::vector<Component*> m_components;

public:
	Machine(unsigned int id, std::string name)
	{
		m_id = id;
		m_name = name;
	}

	void AddComponent(Component*& component)
	{
		m_components.push_back(component);	
	}
	
	unsigned int Price()
	{
		for (size_t i = 0; i < m_components.size(); i++)
		{
			m_price += m_components[i]->C_Price();
		}
		return m_price;
	}

	void PrintComponents()
	{
		std::cout << m_name << " id: " << m_id << " consists of:\n";
		for (size_t i = 0; i < m_components.size(); i++)
			std::cout << m_components[i]->Name() << ", " << m_components[i]->C_Price() << " rubles\n";
	}
};

int main()
{
	unsigned int id, number;
	std::string model, name;
	unsigned int price;

	std::cout << "Enter the id and model of the machine: ";
	std::cin >> id >> model;

	Machine* machine = new Machine(id, model);

	std::cout << "Enter the amount of components: ";
	std::cin >> number;

	std::cout << "Enter the name and the price of a component: ";
	for (size_t i = 0; i < number; i++)
	{
		std::cout << i+1 << " component: ";
		std::cin >> name >> price;
		Component* component = new Component(i, name, price);
		machine->AddComponent(component);
	}

	machine->PrintComponents();

	std::cout << "The price of machine is " << machine->Price() << " rubles";

	delete machine;

	return 0;
}