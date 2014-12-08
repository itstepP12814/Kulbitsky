#include "time.h"

Time::Time(){
	hours = 0;
	minutes = 0;
}

Time::Time(unsigned hours, unsigned minutes){
	this->hours = hours;
	this->minutes = minutes;

}


Time Time::operator+(const Time& source) const{
	Time result;
	result.minutes = (minutes + source.minutes) % 60;
	result.hours = (hours + source.hours + (minutes + source.minutes) / 60) % 24;
	return result;
} 

Time Time::operator-(const Time& source) const{
	Time result;
	result.hours = hours - source.hours;
	result.minutes = minutes - source.minutes;
	if (result.minutes < 0) {
		result.minutes += 60;
		result.hours--;
	}
	if (result.hours < 0) {
		result.hours = 0;
		result.minutes = 0;
	
	}
	
	return result;

}

bool Time::operator>(const Time& source) const{
	if (hours > source.hours)
		return true;
	else
		if (hours < source.hours)
			return false;
		else 
			if (minutes > source.minutes)
				return true;
			else
				return false;
}

bool Time::operator<(const Time& source) const{
	if (this->operator>(source)) return false;
	else return true;

}

bool Time::operator==(const Time& source) const{
	if ((hours == source.hours)&&(minutes == source.minutes))
		return true;
	else return false;
}

bool Time::operator!=(const Time& source) const{
	if (this->operator==(source)) return false;
	else return true;
}

bool Time::operator>=(const Time& source) const{
	if ((this->operator>(source))||(this->operator==(source))) return true;
	else return false;
}

bool Time::operator<=(const Time& source) const{
	if ((this->operator<(source))||(this->operator==(source))) return true;
	else return false;
}

ostream& operator<< (ostream& s, Time& t){
	if (t.hours < 10) s << 0;
	s << t.hours << " : ";
	if (t.minutes < 10) s << 0;
	s << t.minutes;
	return s;
}

void Time::setTime(){
	cout << "Enter the time" << endl;
	cout << "hours: ";
	cin >> this->hours;
	cout << "minutes: ";
	cin >> this->minutes;
	cout << "am/pm (no- for Europe): ";
	char c;
	cin >> c;
	if ((c == 'a')||(c == 'A')) this->hours += 12;
}

void Time::print(){
	if (this->hours > 12) {
		this->hours -= 12;
		cout << *this << " pm" << endl;
	} else 
		cout << *this << " am" << endl;





}