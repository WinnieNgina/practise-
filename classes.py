class Voter:
    def _int_(self, name, year, id_number):
        self.name = name
        self.year = year
        self.id_number = id_number

    def get_user(self):
        self.name = input("Please enter your name : ")
        self.year = int(input ("Please enter your year of birth: "))
        self.id_number = input ("Please enter your id number: ")

    def validate(self):
        if not self.name:
            raise ValueError("missing name")
        if (2023 - self.year) > 18:
            print("Name:", self.name, ",id number:", self.id_number)
            print("You can proceed and cast your vote")
        else:
            print(self.name, "you cannot vote. Only individuals above 18 years can vote")
voter1 = Voter()
voter1.get_user()
voter1.validate()
