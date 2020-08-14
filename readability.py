from cs50 import get_string

text = get_string('Text: ')

lettercounter = 0
wordcounter = 1
sentencecounter = 0

for i in text:
        if i >= 'A' and i <= 'Z' or  i >= 'a' and  i <= 'z':
            lettercounter += 1
        elif i == ' ':
            wordcounter += 1
        elif i == '.' or i == '?' or i == '!':
            sentencecounter += 1;
            
print(lettercounter);
print(wordcounter);
print(sentencecounter);

L = (lettercounter * 100) / wordcounter
S = (sentencecounter * 100) / wordcounter
index = 0.0588 * L - 0.296 * S - 15.8;
grade = round(index)

if grade >= 16:
    print('Grade 16+')
elif grade < 1:
    print('Before Grade 1')
else:
    print(f'Grade {grade}'')
