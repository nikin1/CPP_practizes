
class Date {
    private:
        int day;
        int month;
        int year;
    
    public:
        Date(int d, int m, int y);
    
        int GetDay() const;
        int GetMonth() const;
        int GetYear() const;
    
        Date operator + (int d) const {
            return Date(day + d, month, year);
        }
        Date operator - (int d) const {
            return Date(day - d, month, year);
        }
    
        int TotalDays() const {
            return year * 365 + month * 31 + day;
        }
    
    
    
    
    
    };
    
    Date::Date(int d, int m, int y) {
        
        int  flag = 0;
        if (d < 0 || d > 31) {
            flag = 1;
        }
        if (m < 0 || m > 12) {
            flag = 1;
        }
        if (y < 1970 || y > 2099) {
            flag = 1;
        }




    
        if (!flag) { // если всё нормально, доп. проверяем дни
            if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
                if (d > 31) flag = 1;
            } else if (m == 2) {
                if (y % 4 == 0) {
                    if (d > 28) flag = 1;
                } else {
                    if (d > 29) flag = 1;
                }
            } else {
                if (d > 30) flag = 1;

            }
        }
    
    
        if (flag) {
            day = 1;
            month = 1;
            year = 1970;
        } else {
            day = d;
            month = m;
            year = y;
        }
    
    
    
    }
    
    int Date::GetDay() const{
        return day;
    }
    
    int Date::GetMonth() const{
        return month;
    }
    
    int Date::GetYear() const{
        return year;
    }
    
    
    int operator - (const Date& D1, const Date& D2) {
        return D1.TotalDays() - D2.TotalDays();
    }
    
