#ifndef ENUMS_MY_ENUMS_H
#define ENUMS_MY_ENUMS_H

namespace HumanEnums {
    enum Gender {
        MALE,
        FEMALE
    };

    enum Religion {
        CHRISTIANITY,
        ISLAM,
        JUDAISM,
        MORMONISM,
        ATHEISM,
        JEHOVAHSWITNESS
    };

    enum Race {
        CAUCASIANS,
        NEGROES,
        MONGOLOID,
        AUSTRALOID,
        RACE
    };
}

namespace DrinkAndFoodEnums {
    enum Food {
        SPINACH,
        WALNUTS,
        BEETS,
        AVOCADO,
        LENTILS,
        RASPBERRIES,
        LEMONS
    };

    enum Drink {
        WATER,
        MILK,
        BEER,
        COFFEE,
        TEA,
        SODA
    };
}

namespace Colors {
    enum Color {
        BLACK,
        WHITE,
        RED,
        GREEN,
        BLUE
    };
}

namespace Programming {
    namespace ProgrammingLanguageParadigm {
        namespace DeclarativeProgrammingLanguages {
            enum Logic {
                NONE,
                PROLOG
            };

            enum Functional {
                NONE,
                LISP,
                APL,
                SCHEME
            };

            enum Database {
                NONE,
                MONGODB,
                SQL
            };
        }

        namespace ImperativeProgrammingLanguages {
            enum Procedural {
                NONE,
                C,
                PASCAL,
                FORTRAN,
                BASIC,
            };

            enum ObjOriented {
                NONE,
                ADA,
                OBJECTPASCAL,
                CPLUSPLUS,
                JAVA,
                JAVASCRIPT,
                PYTHON,
                SMALLTALK,
                EIFFEL
            };

            enum ParallelProcessing {
                NONE,
                ADA,
                PASCALS,
                OCCAM,
                GO
            };
        }
    }

    enum Ide {
        NONE,
        CLION,
        NETBEANS,
        ECLIPSE,
        VISUALSTUDIO,
        XCODE
    };

    namespace TextEditors {
        enum ConsoleTextEditor {
            NONE,
            VIM,
            EMACS,
            NANO,
            NVIM
        };

        enum GuiTextEditor {
            NONE,
            VISUALCODE,
            SUBLIMETEXT,
            ATOM,
            BRACKETS
        };
    }


    enum ProgrammerType {
        FRONTENDDEVELOPER = 0,
        BACKENDDEVELOPER,
        FULLSTACKDEVELOPER,
        DEVOPSENGINNER,
        DATASCIENTIST,
        AIDEVELOPER
    };

    enum ProgrammerLevel {
        LEARNER = 0,
        JUNIOR,
        MIDDLE,
        SENIOR,
        LEAD
    };

    enum OperatingSystem {
        LINUX = 0,
        MACOS,
        UNIX,
        WIN
    };

    enum Company {
        MICROSOFT = 0,
        ALPHABET,
        APPLE,
        SAMSUNG,
        ORACLE
    };
}

#endif