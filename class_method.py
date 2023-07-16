    def do_show(self, line):
        """Prints string representation of an instance"""
        args = line.split()
        if len(args) < 2:
            print("** class name missing **")
            return
        class_name = args[0]
        instance_id = args[1]
        key = class_name + "." + instance_id
        if class_name in self.classes:
            objects = models.storage.all()
            if key in objects:
                print(objects[key])
            else:
                print("** no instance found **")
        else:
            print("** class doesn't exist **")



    def do_destroy(self, line):
        """Deletes an instance based on the class name and id"""
        args = line.split()
        if len(args) < 2:
            print("** class name missing **")
            return
        class_name = args[0]
        instance_id = args[1]
        key = class_name + "." + instance_id
        if class_name in self.classes:
            objects = models.storage.all()
            if key in objects:
                del objects[key]
                models.storage.save()
            else:
                print("** no instance found **")
        else:
            print("** class doesn't exist **")


    def do_update(self, line):
        """
        Updates an instance based on the class name
        and id by adding or updating attribute
        """
        args = self.custom_split(line)

        if not args:
            print("** class name missing **")
            return

        class_name = args[0]

        if class_name not in self.classes:
            print("** class doesn't exist **")
            return

        if len(args) < 2:
            print("** instance id missing **")
            return

        instance_id = args[1]
        key = class_name + "." + instance_id

        if key not in models.storage.all():
            print("** no instance found **")
            return

        if len(args) < 3:
            print("** dictionary missing **")
            return

        try:
            update_dict = eval(args[2])
            if type(update_dict) != dict:
                raise ValueError
        except (NameError, SyntaxError, ValueError):
            print("** invalid dictionary format **")
            return

        instance = models.storage.all()[key]
        for attr, value in update_dict.items():
            setattr(instance, attr, value)
        models.storage.save()

    def default(self, line):
        """Default command handler method"""
        if line.endswith(".all()"):
            class_name = line[:-6]
            self.do_all(class_name)
        elif line.endswith(".count()"):
            class_name = line[:-8]
            self.do_count(class_name)
        elif line.startswith("show(") and line.endswith(")"):
            args = line[5:-1].split(',')
            class_name = args[0].strip()
            instance_id = args[1].strip() if len(args) > 1 else ""
            key = class_name + "." + instance_id
            if class_name in self.classes:
                objects = models.storage.all()
                if key in objects:
                    print(objects[key])
                else:
                    print("** no instance found **")
            else:
                print("** class doesn't exist **")
        elif line.startswith("destroy(") and line.endswith(")"):
            args = line[8:-1].split(',')
            class_name = args[0].strip()
            instance_id = args[1].strip() if len(args) > 1 else ""
            key = class_name + "." + instance_id
            if class_name in self.classes:
                objects = models.storage.all()
                if key in objects:
                    del objects[key]
                    models.storage.save()
                else:
                    print("** no instance found **")
            else:
                print("** class doesn't exist **")
        else:
            print("*** Unknown syntax: {}".format(line))

        elif line.startswith("update(") and line.endswith(")"):
            args = line[7:-1].split(',')
            class_name = args[0].strip()
            instance_id = args[1].strip() if len(args) > 1 else ""
            key = class_name + "." + instance_id
            if class_name in self.classes:
                objects = models.storage.all()
                if key in objects:
                    if len(args) < 4:
                        print("** attribute name missing **")
                    elif len(args) < 5:
                        print("** value missing **")
                    else:
                        attribute_name = args[2].strip()
                        attribute_value = args[3].strip()
                        instance = objects[key]
                        try:
                            attribute_value = eval(attribute_value)
                        except (NameError, SyntaxError):
                            pass
                        setattr(instance, attribute_name, attribute_value)
                        models.storage.save()
                else:
                    print("** no instance found **")
            else:
                print("** class doesn't exist **")
        else:
            print("*** Unknown syntax: {}".format(line))
    
