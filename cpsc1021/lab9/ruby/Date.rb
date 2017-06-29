#  Basic Class definition in Ruby
class Date
  # This makes getters and setters for us!
  attr_accessor :month, :day, :year
  @@months = ["Jan", "Feb", "Mar", "Apr",
              "May", "Jun", "Jul", "Aug",
              "Sep", "Oct", "Nov", "Dec"]

  # Constructor
  def initialize(month, day, year)
    @month = month
    @day = day
    @year = year
  end

  # This is a toString method!
  # In Ruby, the last statement executed in a method is the return value if
  # there is no explicit return
  def to_s
    "#{@@months[@month-1]} #{@day}, #{@year}"
  end

  # ================== Fix Me! ================
  # Is the given date older than me?
  def older?(d)
    # TODO: Implement me!
  end
  # ================== ^^^^^^ ================

end

# Make some Dates
d1 = Date.new(10,5,1993)
d2 = Date.new(8,3,1895)
d3 = Date.new(4,3,2000)

# Make them into an array
dates = [d1,d2,d3]
oldest_date = dates[0]

# Loop over the dates and find the oldest
for date in dates do
  oldest_date = date if date.older?(oldest_date)
end

puts oldest_date
