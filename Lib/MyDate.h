#pragma once
#pragma warning(disable : 4996)
#include <iostream>
using namespace std;



class clsMyDate
{
public:
	short ReadYear()
	{
		short Year = 0;
		cout << "Plaese Enter A Year : ";
		cin >> Year;
		return Year;
	}
	short ReadMonth()
	{
		short Month = 0;
		cout << "Plaese Enter A Month : ";
		cin >> Month;
		return Month;
	}
	short ReadDay()
	{
		short Day = 0;
		cout << "Plaese Enter A Day : ";
		cin >> Day;
		return Day;
	}

	bool IsLeapYear(short Year)
	{
		return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
	}

	short NumberOfDaysInAMonth(short Year, short Month)
	{
		if (Month < 1 || Month>12)
			return  0;

		int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

		return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
	}
	struct stDate
	{
		short Day;
		short Month;
		short Year;
	};

	stDate ReadFullDate()
	{
		stDate Date;
		Date.Day = ReadDay();
		Date.Month = ReadMonth();
		Date.Year = ReadYear();
		return Date;
	}
	bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
	{
		return (Date1.Year < Date2.Year) ? true :
			((Date1.Year == Date2.Year) ?
				(Date1.Month < Date2.Month ? true :
					(Date1.Month == Date2.Month ?
						Date1.Day < Date2.Day : false)) : false);
	}
	bool IsLastDayInAMonth(stDate Date)
	{
		return (Date.Day == NumberOfDaysInAMonth(Date.Year, Date.Month));
	}
	bool IsLastMonthInAYear(short Month)
	{
		return (Month == 12);
	}
	stDate IncreqseDateByOneDay(stDate Date)
	{
		if (IsLastDayInAMonth(Date))
		{
			if (IsLastMonthInAYear(Date.Month))
			{
				Date.Day = 1;
				Date.Month = 1;
				Date.Year++;
			}
			else
			{
				Date.Month++;
				Date.Day = 1;
			}
		}
		else
		{
			Date.Day++;
		}
		return Date;
	}
	stDate IncreaseDateByXDays(int XDays, stDate Date)
	{
		for (int i = 1; i <= XDays; i++)
		{
			Date = IncreqseDateByOneDay(Date);
		}
		return Date;
	}
	stDate IncreaseDateByOneWeek(stDate Date)
	{
		for (short i = 1; i <= 7; i++)
		{
			Date = IncreqseDateByOneDay(Date);
		}
		return Date;
	}
	stDate IncreaseDateByXWeek(short Xweeks, stDate Date)
	{
		for (short i = 1; i <= Xweeks; i++)
		{
			Date = IncreaseDateByOneWeek(Date);
		}
		return Date;
	}
	stDate ClampdayToValid(stDate Date)
	{
		short NumberOfDaysInCurrentMonth =
			NumberOfDaysInAMonth(Date.Year, Date.Month);
		if (Date.Day > NumberOfDaysInCurrentMonth)
		{
			Date.Day = NumberOfDaysInCurrentMonth;
		}
		return Date;
	}
	stDate IncreaseDateByOneMonth(stDate Date)
	{
		if (Date.Month == 12)
		{
			Date.Month = 1;
			Date.Year++;
		}
		else
		{
			Date.Month++;
		}

		Date = ClampdayToValid(Date);
		return Date;

	}
	stDate IncreaseDateByXMonth(int XMonth, stDate Date)
	{
		for (int i = 1; i <= XMonth; i++)
		{
			Date = IncreaseDateByOneMonth(Date);
		}
		return Date;
	}
	stDate IncreaseDateByOneYear(stDate Date)
	{
		Date.Year++;
		Date = ClampdayToValid(Date);
		return Date;
	}
	stDate IncreaseDateByXYear(int XYear, stDate Date)
	{
		for (int i = 1; i <= XYear; i++)
		{
			Date = IncreaseDateByOneYear(Date);
		}
		return Date;
	}
	stDate IncreaseDateByXYearFaster(int XYears, stDate Date)
	{
		Date.Year += XYears;
		Date = ClampdayToValid(Date);
		return Date;
	}
	stDate IcreaseDateByOneDecode(stDate Date)
	{
		Date = IncreaseDateByXYearFaster(10, Date);
		return Date;
	}
	stDate IncreaseDateByXDecodes(short XDecodes, stDate Date)
	{
		for (short i = 1; i <= XDecodes; i++)
		{
			Date = IcreaseDateByOneDecode(Date);
		}
		return Date;
	}
	stDate IncreaseDateByXDecodesFaster(short XDecodes, stDate Date)
	{
		Date.Year += (XDecodes * 10);
		Date = ClampdayToValid(Date);
		return Date;
	}
	stDate IncreaseDateByCentury(stDate Date)
	{
		Date = IncreaseDateByXDecodesFaster(10, Date);
		return Date;
	}
	stDate IncreaseDateByOneMillenium(stDate Date)
	{
		Date.Year += 1000;
		Date = ClampdayToValid(Date);
		return Date;
	}

	bool IsFirstDayInAMonth(short Day)
	{
		return (Day == 1);
	}
	bool IsFirstMonthInAYear(short Month)
	{
		return (Month == 1);
	}

	stDate ClampdayToValid(stDate Date)
	{
		short NumberOfDaysInCurrentMonth =
			NumberOfDaysInAMonth(Date.Year, Date.Month);
		if (Date.Day > NumberOfDaysInCurrentMonth)
		{
			Date.Day = NumberOfDaysInCurrentMonth;
		}
		return Date;
	}
	stDate DecreaseDateByOneDay(stDate Date)
	{
		if (IsFirstDayInAMonth(Date.Day))
		{
			if (IsFirstMonthInAYear(Date.Month))
			{
				Date.Day = 31;
				Date.Month = 12;
				Date.Year--;
			}
			else
			{
				Date.Month--;
				Date.Day = NumberOfDaysInAMonth(Date.Year, Date.Month);
			}
		}
		else
		{
			Date.Day--;
		}
		return Date;
	}
	stDate DecreaseDateByXDay(int XDay, stDate Date)
	{
		for (int i = 1; i <= XDay; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}
	stDate DecreaseDateByOneWeek(stDate Date)
	{
		for (short i = 1; i <= 7; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}
	stDate DecreaseDateByXWeek(int XWeek, stDate Date)
	{
		for (int i = 1; i <= XWeek; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}
	stDate DecreaseDateByOneMonth(stDate Date)
	{
		if (IsFirstMonthInAYear(Date.Month))
		{
			Date.Year--;
			Date.Month = 12;
		}
		else
		{
			Date.Month--;
		}
		Date = ClampdayToValid(Date);
		return Date;
	}
	stDate DecreaseDateByXMonth(short XMonth, stDate Date)
	{
		for (short i = 1; i <= XMonth; i++)
		{
			Date = DecreaseDateByOneMonth(Date);
		}
		return Date;
	}
	stDate DecreaseDateByOneYear(stDate Date)
	{
		Date.Year--;
		Date = ClampdayToValid(Date);
		return Date;
	}
	stDate DecreaseDateByXYear(short XYear, stDate Date)
	{
		for (short i = 1; i <= XYear; i++)
		{
			Date = DecreaseDateByOneYear(Date);
		}
		return Date;
	}
	stDate DecreaseDateByXYearFaster(short XYear, stDate Date)
	{
		Date.Year -= XYear;
		Date = ClampdayToValid(Date);
		return Date;
	}
	stDate DecreaseDateByOneDecade(stDate Date)
	{
		Date = DecreaseDateByXYearFaster(10, Date);
		return Date;
	}
	stDate DecreaseDateByXDecades(short XDecades, stDate Date)
	{
		for (short i = 1; i <= XDecades; i++)
		{
			Date = DecreaseDateByOneDecade(Date);
		}
		return Date;
	}
	stDate DecreaseDateByXDecadesFaster(short XDecades, stDate Date)
	{
		Date.Year -= (XDecades * 10);
		Date = ClampdayToValid(Date);
		return Date;
	}

	stDate DecreaseDateByOneCentury(stDate Date)
	{
		Date.Year -= 100;
		Date = ClampdayToValid(Date);
		return Date;
	}
	stDate DecreaseDateByOneMillenium(stDate Date)
	{
		Date.Year -= 1000;
		Date = ClampdayToValid(Date);
		return Date;
	}
}
	