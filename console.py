#!/usr/bin/python3
# Command Intepreter
import cmd
from models import base_model
import models

class HBNBCommand(cmd.Cmd):
    """
    Create class HBNBCommand
    """
    prompt = "(hbnb)"  # Set your custom prompt here

    def do_EOF(self, line):
        """Checks end of file"""
        return True

    def do_quit(self, arg):
        """Quit command to exit the program"""
        return True

    def emptyline(self):
        """Do nothing if empty line is passed"""
        pass

    def do_create(self, args):
        """Creates a new instance"""
        if args:
            if hasattr(base_model, args):
                # class_obj = getattr(base_model, args)
                dummy_instance = base_model.BaseModel()
                dummy_instance.save()
                print(dummy_instance.id)
            else:
                print("** class doesn't exist **")
        else:
            print("** class name missing **")

    def do_show(self, line):
        """Prints str repr of instance"""
        args = line.split()

        if len(args) == 0:
            print("** class name missing **")
            return
        class_name = args[0]
        if not hasattr(base_model, class_name):
            print("** class doesn't exist **")
            return
        if len(args) == 1:
            print("** instance id missing **")
            return

        inst_id = args[1]
        objs = models.storage.all()
        for inst_name_id, inst in objs.items():
            cls_name_id = inst_name_id.split(".")
            if inst_id == cls_name_id[1] and class_name == cls_name_id[0]:
                print(inst)
                return
            print("** no instance found **")
            return

    def do_destroy(self, line):
        """Deletes an instance based on the class name and id"""
        args = line.split()

        if len(args) == 0:
            print("** class name missing **")
            return
        if hasattr(base_model, args[0]):
            if len(args) == 1:
                print("** instance id missing **")
                return
            objs = models.storage.all()
            for inst_name_id, inst  in objs.items():
                cls_name_id = inst_name_id.split(".")
                if args[1] == cls_name_id[1] and args[0] == cls_name_id[0]:
                    del objs[inst_name_id]
                    models.storage.save()
                    return
                else:
                    print("** no instance found **")
                    return
        else:
            print("** class doesn't exist **")
            return

    def do_all(self, line):
        """
        Prints all string representation of all
        instances based or not on the class name
        """
        list_objs =[]
        if hasattr(base_model, line):
            objs = models.storage.all()
            for inst_name_id, inst  in objs.items():
                cls_name_id = inst_name_id.split(".")
                if line == cls_name_id[0]:
                    list_objs.append(str(inst))
            print(list_objs)
        else:
            print("** class doesn't exist **")
    
    def custom_split(self, line):
        args = []
        current_arg = ""
        inside_quotes = False

        for char in line:
            if char == '"':
                inside_quotes = not inside_quotes
            elif char == ' ' and not inside_quotes:
                if current_arg:
                    args.append(current_arg)
                    current_arg = ""
                continue

            current_arg += char

        if current_arg:
            args.append(current_arg)

        return args


    def do_update(self, line):
        """
        Updates an instance based on the class name
        and id by adding or updating attribute
        """
        args = self.custom_split(line)
        objs = models.storage.all()
        
        if len(args) == 0:
            print("** class name missing **")
            return
        if hasattr(base_model, args[0]):
            if len(args) == 1:
                print("** instance id missing **")
                return
            for inst_name_id, inst  in objs.items():
                cls_name_id = inst_name_id.split(".")
                if args[0] == cls_name_id[0] and args[1] == cls_name_id[1]:
                    if len(args) == 2:
                        print("** attribute name missing **")
                        return
                    elif len(args) == 3:
                        print("** value missing **")
                        return
                    else:
                        attribute_name = args[2]
                        attribute_value = args[3]
                        if hasattr(inst, attribute_name):
                            # Retrieve the current value
                            current_value = getattr(inst, attribute_name)
                            # Prompt the user for a new value
                            new_value = attribute_value
                            # Type cast the new value to match the existing attribute's type
                            if isinstance(current_value, int):
                                new_value = int(new_value)
                            elif isinstance(current_value, float):
                                new_value = float(new_value)
                                # Add more type checks for other types if necessary
                                # Update the attribute with the new value
                            elif isinstance(current_value, str):
                                new_value = str(new_value)
                            setattr(inst, attribute_name, new_value)
                        else:
                            setattr(inst, attribute_name, attribute_value)
                        models.storage.save()
                        return

                else:
                    print("** no instance found **")
                    return
        else:
            print("** class doesn't exist **")
            return


if __name__ == '__main__':
    HBNBCommand().cmdloop()
