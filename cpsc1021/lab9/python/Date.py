# Basic class definition
class Date(object):
    DATES = ["Jan", "Feb", "Mar", "Apr",
              "May", "Jun", "Jul", "Aug",
              "Sep", "Oct", "Nov", "Dec"]

    # Constructor
    def __init__(self, month, day, year):
        self.month = month
        self.day = day
        self.year = year

    # toString
    def to_s(self):
        return "{0} {1}, {2}".format(Date.DATES[self.month-1], self.day, self.year)

    # ================== Fix Me! ================
    # Am I older than Date d?
    def older(self, d):
        if self.year < d.year:
            return True
        elif self.year == d.year:
            if self.month < d.month:
                return True
            elif self.month == d.month:
                if self.day < d.day:
                    return True
    # ================== ^^^^^^ ================


# Make some Dates
d1 = Date(10,5,1993)
d2 = Date(8,3,1895)
d3 = Date(4,3,2000)

# Make them into an array
dates = [d1,d2,d3]
oldest_date = dates[0]

# Loop over the dates and find the oldest
for date in dates:
    if date.older(oldest_date):
        oldest_date = date

print oldest_date.to_s()
