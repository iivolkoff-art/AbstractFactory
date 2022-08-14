#include <iostream>
using namespace std;


class Toyota {
public:
    virtual string NameToyota() = 0;
};

class ToyotaSport : public Toyota {
public:
    string NameToyota() override {
        return "ToyotaSport";
    }
};

class ToyotaBuisnes : public Toyota {
public:
    string NameToyota() override {
        return "ToyotaBuisnes";
    }
};


class Audi {
public:
    virtual string NameAudi() = 0;
    virtual string AllName(Toyota& toyota) = 0;
};

class AudiSport : public Audi {
public:
    string NameAudi() override {
        return "AudiSport";
    }
    string AllName(Toyota& toyota) override {
        string result = toyota.NameToyota();
        return "Результат AudiSport и " + result;
    }
};

class AudiBuisnes : public Audi {
    string NameAudi() override {
        return "AudiBuisnes";
    }
    string AllName(Toyota& toyota) override {
        string result = toyota.NameToyota();
        return "Результат AudiBuisnes и " + result;
    }
};


class BMW {
public:
    virtual string NameBMW() = 0;
    virtual string AllName(Toyota& toyota, Audi& audi) = 0;
};

class BMWSport : public BMW {
    string NameBMW() override {
        return "BMWSport";
    }
    string AllName(Toyota& toyota, Audi& audi) override {
        string result = toyota.NameToyota() + " " + audi.NameAudi();
        return "Результат BMWSport и " + result;
    }
};

class BMWBuisnes : public BMW {
    string NameBMW() override {
        return "BMWBuisnes";
    }
    string AllName(Toyota& toyota, Audi& audi) override {
        string result = toyota.NameToyota() + " " + audi.NameAudi();
        return "Результат BMWBuisnes и " + result;
    }
};


class AbstractFactory {
public:
    virtual Toyota* CreateToyota() = 0;
    virtual Audi* CreateAudi() = 0;
    virtual BMW* CreateBMW() = 0;
};

class SportFactory : public AbstractFactory {
public:
    Toyota* CreateToyota() override {
        return new ToyotaSport;
    }
    Audi* CreateAudi() override {
        return new AudiSport;
    }
    BMW* CreateBMW() override {
        return new BMWSport;
    }
};

class BuisnesFactory : public AbstractFactory {
public:
    Toyota* CreateToyota() override {
        return new ToyotaBuisnes;
    }
    Audi* CreateAudi() override {
        return new AudiBuisnes;
    }
    BMW* CreateBMW() override {
        return new BMWBuisnes;
    }
};


void ClientCode(AbstractFactory& abstractfactory) {
    Toyota* toyota = abstractfactory.CreateToyota();
    Audi* audi = abstractfactory.CreateAudi();
    BMW* bmw = abstractfactory.CreateBMW();
    cout << bmw->NameBMW() << endl;
    cout << bmw->AllName(*toyota, *audi) << endl;
    delete toyota;
    delete audi;
    delete bmw;
}


int main() {
    setlocale(LC_ALL, "RUS");
    cout << "SPORT - 1 \t BUISNES - 2 \nиспользуется модель BMW*" << endl;
    int Choise;
    cin >> Choise;
    system("cls");
    if (Choise == 1) {
        cout << "Тестирование с Sport машинами:" << endl;
        SportFactory* f1 = new SportFactory();
        ClientCode(*f1);
        delete f1;
    }
    else if (Choise == 2) {
        cout << "Тестирование с Buisnes машинами:" << endl;
        BuisnesFactory* f2 = new BuisnesFactory();
        ClientCode(*f2);
        delete f2;
    }
    else {
        system("cls");
        main();
    }
}