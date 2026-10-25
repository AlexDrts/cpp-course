#include <iostream>
#include <windows.h>
#include <string>
using namespace std;


class KETTLE {
private:
	char* nickname;
	string color;
	string company;
	int power;
	int release_year;
public:

	KETTLE() : KETTLE("kettle", "red", "Philips", 1500, 2023) {}

	KETTLE(const char* nickname, string color, string company, int power, int release_year) {
		cout << "C-TOR!\n";
		SetNickname(nickname);
		SetColor(color);
		SetCompany(company);
		SetPower(power);
		SetRelease_year(release_year);
	}

	//------------

	void SetNickname(const char* nickname) {
		int length = strlen(nickname) + 1; // +1 for \0
		this->nickname = new char[length];
		strcpy_s(this->nickname, length, nickname);
	}

	string GetNickname() const {
		return nickname;
	}
	//------------

	void SetColor(const string& color) {
		this->color = color;
	}

	string GetColor() const {
		return color;
	}
	//------------

	void SetCompany(const string& company) {
		this->company = company;
	}

	string GetCompany() const {
		return company;
	}
	//------------

	void SetPower(int power) {
		if (power < 1000 || power > 3000) {
			cout << "Incorrect value for power. Please, enter value from 1000 to 3000 (W).\n";
		}
		else {
			this->power = power;
		}
	}

	int GetPower() const {
		return power;
	}
	//------------

	void SetRelease_year(int release_year) {
		if (release_year < 2020 || release_year > 2025) {
			cout << "Incorrect value for release_year. Please, enter value from 2020 to 2025.\n";
		}
		else {
			this->release_year = release_year;
		}
	}

	int GetRelease_year() const {
		return release_year;
	}
	//------------

	void Info() const {
		cout << "============================\n";
		cout << "Kettle nickname: " << nickname << "\n";
		cout << "Kettle color: " << color << "\n";
		cout << "Kettle company: " << company << "\n";
		cout << "Kettle power: " << power << " W\n";
		cout << "Kettle release year: " << release_year << "\n";
		cout << "============================\n";
	}
};

//-----------------------------------------------------------------------------

class SPEAKER {
private:
	char* nickname;
	string color;
	string company;
	int volume;
	int power;
public:

	SPEAKER() : SPEAKER("speaker", "red", "JBL", 50, 80) {}

	SPEAKER(const char* nickname, string color, string company, int volume, int power) {
		cout << "C-TOR!\n";
		SetNickname(nickname);
		SetColor(color);
		SetCompany(company);
		SetVolume(volume);
		SetPower(power);
	}


	void SetNickname(const char* nickname) {
		int length = strlen(nickname) + 1; // +1 for \0
		this->nickname = new char[length];
		strcpy_s(this->nickname, length, nickname);
	}

	string GetNickname() const {
		return nickname;
	}
	//------------

	void SetColor(const string& color) {
		this->color = color;
	}

	string GetColor() const {
		return color;
	}
	//------------

	void SetCompany(const string& company) {
		this->company = company;
	}

	string GetCompany() const {
		return company;
	}
	//------------

	void SetVolume(int volume) {
		if (volume < 5 || volume > 200) {
			cout << "Incorrect value for volume. Please, enter value from 5 to 200 (W).\n";
		}
		else {
			this->volume = volume;
		}
	}

	int GetVolume() const {
		return volume;
	}
	//------------

	void SetPower(int power) {
		if (power < 0 || power > 100) {
			cout << "Incorrect value for power. Please, enter value from 0 to 100 (%).\n";
		}
		else {
			this->power = power;
		}
	}

	int GetPower() const {
		return power;
	}
	//------------

	void Info() const {
		cout << "============================\n";
		cout << "Speaker nickname: " << nickname << "\n";
		cout << "Speaker color: " << color << "\n";
		cout << "Speaker company: " << company << "\n";
		cout << "Speaker volume: " << volume << "\n";
		cout << "Speaker power: " << power << "\n";
		cout << "============================\n";
	}
};

//-----------------------------------------------------------------------------

class TELEPHONE {
private:
	char* nickname;
	string color;
	string company;
	int model;
	int battery;
public:

	TELEPHONE() : TELEPHONE("telephone", "black", "Apple", 14, 4500) {}

	TELEPHONE(const char* nickname, string color, string company, int model, int battery) {
		cout << "C-TOR!\n";
		SetNickname(nickname);
		SetColor(color);
		SetCompany(company);
		SetModel(model);
		SetBattery(battery);
	}


	void SetNickname(const char* nickname) {
		int length = strlen(nickname) + 1; // +1 for \0
		this->nickname = new char[length];
		strcpy_s(this->nickname, length, nickname);
	}

	string GetNickname() const {
		return nickname;
	}
	//------------

	void SetColor(const string& color) {
		this->color = color;
	}

	string GetColor() const {
		return color;
	}
	//------------

	void SetCompany(const string& company) {
		this->company = company;
	}

	string GetCompany() const {
		return company;
	}
	//------------

	void SetModel(int model) {
		if (model < 12 || model > 16) {
			cout << "Incorrect value for model. Please, enter value from 12 to 16.\n";
		}
		else {
			this->model = model;
		}
	}

	int GetModel() const {
		return model;
	}
	//------------

	void SetBattery(int battery) {
		if (battery < 3500 || battery > 7000) {
			cout << "Incorrect value for battery. Please, enter value from 3500 to 7000 (mAh).\n";
		}
		else {
			this->battery = battery;
		}
	}

	int GetBattery() const {
		return battery;
	}
	//------------

	void Info() const {
		cout << "============================\n";
		cout << "Telephone nickname: " << nickname << "\n";
		cout << "Telephone color: " << color << "\n";
		cout << "Telephone company: " << company << "\n";
		cout << "Telephone model: " << model << "\n";
		cout << "Telephone battery: " << battery << " (mAh)\n";
		cout << "============================\n";
	}
};

//-----------------------------------------------------------------------------

class MICROWAVE {
private:
	char* nickname;
	string color;
	string company;
	int power;
public:

	MICROWAVE() : MICROWAVE("microwave", "white", "Samsung", 1200) {}

	MICROWAVE(const char* nickname, string color, string company, int power) {
		cout << "C-TOR!\n";
		SetNickname(nickname);
		SetColor(color);
		SetCompany(company);
		SetPower(power);
	}


	void SetNickname(const char* nickname) {
		int length = strlen(nickname) + 1; // +1 for \0
		this->nickname = new char[length];
		strcpy_s(this->nickname, length, nickname);
	}

	string GetNickname() const {
		return nickname;
	}
	//------------

	void SetColor(const string& color) {
		this->color = color;
	}

	string GetColor() const {
		return color;
	}
	//------------

	void SetCompany(const string& company) {
		this->company = company;
	}

	string GetCompany() const {
		return company;
	}
	//------------

	void SetPower(int power) {
		if (power < 1000 || power > 3500) {
			cout << "Incorrect value for power. Please, enter value from 1000 to 3000 (W).\n";
		}
		else {
			this->power = power;
		}
	}

	int GetPower() const {
		return power;
	}
	//------------

	void Info() const {
		cout << "============================\n";
		cout << "Microwave's nickname: " << nickname << endl;
		cout << "Microwave's color: " << color << endl;
		cout << "Microwave's company: " << company << endl;
		cout << "Microwave's power: " << power << " (W)" << endl;
		cout << "============================\n";
	}
};

//-----------------------------------------------------------------------------

class FLASHLIGHT {
private:
	char* nickname;
	string color;
	string company;
	int power;
	int length;
	int battery;
public:

	FLASHLIGHT() : FLASHLIGHT("flashlight", "yellow", "Xiaomi", 200, 15, 2000) {}

	FLASHLIGHT(const char* nickname, string color, string company, int power, int length, int battery) {
		cout << "C-TOR!\n";
		SetNickname(nickname);
		SetColor(color);
		SetCompany(company);
		SetPower(power);
		SetLength(length);
		SetBattery(battery);
	}


	void SetNickname(const char* nickname) {
		int length = strlen(nickname) + 1; // +1 for \0
		this->nickname = new char[length];
		strcpy_s(this->nickname, length, nickname);
	}

	string GetNickname() const {
		return nickname;
	}
	//------------

	void SetColor(const string& color) {
		this->color = color;
	}

	string GetColor() const {
		return color;
	}
	//------------

	void SetCompany(const string& company) {
		this->company = company;
	}

	string GetCompany() const {
		return company;
	}
	//------------

	void SetPower(int power) {
		if (power < 50 || power > 400) {
			cout << "Incorrect value for power. Please, enter value from 50 to 400 (W).\n";
		}
		else {
			this->power = power;
		}
	}

	int GetPower() const {
		return power;
	}
	//------------

	void SetLength(int length) {
		if (length < 5 || length > 20) {
			cout << "Incorrect value for length. Please, enter value from 5 to 20.\n";
		}
		else {
			this->length = length;
		}
	}

	int GetLength() const {
		return length;
	}
	//------------

	void SetBattery(int battery) {
		if (battery < 1000 || battery > 3000) {
			cout << "Incorrect value for battery. Please, enter value from 1000 to 3000 (mAh).\n";
		}
		else {
			this->battery = battery;
		}
	}

	int GetBattery() const {
		return battery;
	}
	//------------

	void Info() const {
		cout << "============================\n";
		cout << "Flashlight's nickname: " << nickname << endl;
		cout << "Flashlight's color: " << color << endl;
		cout << "Flashlight's company: " << company << endl;
		cout << "Flashlight's power: " << power << " (W)" << endl;
		cout << "Flashlight's length: " << length << " (cm)" << endl;
		cout << "Flashlight's battery: " << battery << " (mAh)" << endl;
		cout << "============================\n";
	}
};

//-----------------------------------------------------------------------------

int main()
{
	KETTLE kettle("kettle", "red", "Philips", 1500, 2023);
	kettle.Info();

	KETTLE k;
	k.Info();

	//-------------
	cout << "\n\n";
	SPEAKER speaker("speaker", "red", "JBL", 50, 80);
	speaker.Info();

	SPEAKER s;
	s.Info();

	//-------------
	cout << "\n\n";
	TELEPHONE telephone("telephone", "black", "Apple", 14, 4500);
	telephone.Info();

	TELEPHONE t;
	t.Info();

	//-------------
	cout << "\n\n";
	MICROWAVE microwave("microwave", "white", "Samsung", 1200);
	microwave.Info();

	MICROWAVE m;
	m.Info();

	//-------------
	cout << "\n\n";
	FLASHLIGHT flashlight("flashlight", "yellow", "Xiaomi", 200, 15, 2000);
	flashlight.Info();

	FLASHLIGHT f;
	f.Info();

}