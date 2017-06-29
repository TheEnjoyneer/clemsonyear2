dog_names = ["Watson", "Chloe", "Oliver"]
my_dog = "Watson"

if dog_names.include?(my_dog) then
  puts "Hey there #{my_dog}!"
  puts "Your name is more than 5 letters long!" if my_dog.length() > 5
else
  puts "Who's pupper are you #{my_dog}?"
end
