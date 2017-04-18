#include <iostream>
#include <cstring>
using namespace std;
class Discount {
public:
    virtual float getDiscount_price() = 0;
    virtual float getPrice() = 0;
};
class Product {
protected:
    char name[100];
    float price;
public:
    Product(const char *name = "", const float price = 0) {
        strcpy(this->name, name);
        this->price = price;
    }
    float getPrice() {
        return price;
    }
};

class DigitalProduct : public Product, public Discount {
private:
    float size;
public:
    DigitalProduct(const char *name = "", const float price = 0, const float size = 0) {
        strcpy(this->name, name);
        this->price = price;
        this->size = size;
    }
    // overriding functions from the base class
    float getDiscount_price() {
        // the discount is 10%
        return 0.9 * getPrice();
    }

    float getPrice() {
        return Product::getPrice();
    }

};

class FoodProduct : public Product, public Discount {
private:
    float calories;
public:
    FoodProduct(const char *name = "", const float price = 0, const float calories = 0) : Product(name, price) {
        this->calories = calories;
    }
    float getDiscount_price() {
        // discount is 20%
        return .8 * getPrice();
    }

    float getPrice() {
        return Product::getPrice();
    }
};

float total_discount(Discount **d, int n) {
    float price = 0;
    for (int i = 0; i < n; ++i) {
        price += d[i]->getPrice();
    }
    float discount = 0;
    for (int i = 0; i < n; ++i) {
        discount += d[i]->getDiscount_price();
    }
    return price - discount;
}
int main() {
    Discount **d = new Discount*[3];
    d[0] = new FoodProduct("Cheese", 450, 1200);
    d[1] = new FoodProduct("Wine", 780, 250);
    d[2] = new DigitalProduct("WOW", 380, 400);
    cout << "Difference: " << total_discount(d, 3) << endl;
    for (int i = 0; i < 3; ++i) {
        delete d[i];
    }
    delete[] d;
    return 0;
}
