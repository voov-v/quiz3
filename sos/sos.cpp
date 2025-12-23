#include <iostream>
#include <string>

class Item {	// 아이템을 선언합니다.
// 공개적인 곳
public:
	Item() {	// 생성자 선언부
		itemName = "";
		itemPrice = 0;	// 정수형 멤버변수 
	}			// 생성자 정의부

	Item(std::string name, int price) {
		itemName = name;
		itemPrice = price;
	}

	~Item() {	// 소멸자 선언부
	}			// 소멸자 정의부

	std::string GetItemName() {
		return itemName;
	}

	int GetItemPrice() {
		return itemPrice;
	}

// 비공개
private:
	std::string itemName; // Item 클래스의 문자열형 멤버변수 itemName을 선언한다.
	int itemPrice; // Item 클래스의 정수형 멤버변수 itemPrice를 선언한다.
}; // 아이템 정의부

template<typename T>
class Inventory {		// 인벤토리의 선언부
public:
	Inventory(int capacity = 10) {	// Inventory 생성자의 선언
		pItems = new  Item[capacity];
		this->capacity = capacity;
		size = 0;
	}

	~Inventory() {
		delete[] pItems;
	}

	void AddItem(Item item) {
		if (size >= capacity)	// 예외처리
			return;

		pItems[size++] = item;
	}

	void RemoveLastItem() {
		size = size - 1;
	}

	void PrintAllItems() {
		for (int i = 0; i < size; i++) {
			std::cout << "Name: " << pItems[i].GetItemName() << ", Price : " << pItems[i].GetItemPrice() << std::endl;
		}
	}

private:
	T* pItems;
	int capacity;
	int size;
};	// 인벤토리의 정의부

// 1. 인벤토리를 만들기
// 2. 인벤토리는 아이템을 가지고 있어요.

// 코드짜기 쉽냐	=>Item
// 코드짜기 어렵냐	=>Inventory는 Item을 관리하기 때문에 어렵다

// 프로그램이 최초에 실행되면 호출되는 함수입니다.
int main() {
	// 포인터는 껍데기입니다.
	Item item("Hello Item", 1000);	 // 정의해야 사용할 수 있음
	Inventory<Item> inventory;
	inventory.AddItem(item);
	inventory.AddItem(Item("Hello Item2", 1100));

	for (int i = 0; i < 10; i++) {
		inventory.AddItem(Item("Hello Item" + std::to_string(i), 100));
	}

	inventory.RemoveLastItem();          // 여기부터 한줄 한줄 실행해보기
	inventory.PrintAllItems();

	// Item*형식을 가진 item을 생성했습니다.
	Item* itemPtr = new Item();	  // 정의해야 사용할 수 있음
	delete itemPtr; // 제거
	return 0;  // 프로그램이 종료될 때, 운영체재에 넘겨주는 값입니다.
}
//선언 > 정의 > 실행 > 생성자 호출 > 왔다갔다 확인 > 소멸 > 종료 완