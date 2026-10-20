#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Info that every student has.
class Student
{
private:
    std::string first_name;
    std::string last_name;
    std::string gpa;

    int graduation_year;
    std::string graduation_semester;

    int enrolled_year;
    std::string enrolled_semester;

    std::string student_level;

public:
    // Set starting values.
    Student()
    {
        first_name = "Unknown";
        last_name = "Unknown";
        gpa = "0.0";

        graduation_year = 0;
        graduation_semester = "Unknown";

        enrolled_year = 0;
        enrolled_semester = "Unknown";

        student_level = "Undergraduate";
    }

    // No internal pointers to delete.
    virtual ~Student()
    {
    }

    void setName(std::string first, std::string last)
    {
        first_name = first;
        last_name = last;
    }

    // Getters only read the info.
    std::string getFirstName() const { return first_name; }
    std::string getLastName() const { return last_name; }

    void setGPA(std::string value) { gpa = value; }
    std::string getGPA() const { return gpa; }

    void setGraduationYear(int year) { graduation_year = year; }
    int getGraduationYear() const { return graduation_year; }

    void setGraduationSemester(std::string semester)
    {
        graduation_semester = semester;
    }

    std::string getGraduationSemester() const
    {
        return graduation_semester;
    }

    void setEnrolledYear(int year) { enrolled_year = year; }
    int getEnrolledYear() const { return enrolled_year; }

    void setEnrolledSemester(std::string semester)
    {
        enrolled_semester = semester;
    }

    std::string getEnrolledSemester() const
    {
        return enrolled_semester;
    }

    void setStudentLevel(std::string level)
    {
        student_level = level;
    }

    std::string getStudentLevel() const
    {
        return student_level;
    }
};

// Art students have an extra emphasis field.
class Art_Student : public Student
{
private:
    std::string art_emphasis;

public:
    Art_Student()
    {
        art_emphasis = "Art Studio";
    }

    ~Art_Student()
    {
    }

    void setArtEmphasis(std::string emphasis)
    {
        // Only allow these three choices.
        if (emphasis == "Art Studio" ||
            emphasis == "Art History" ||
            emphasis == "Art Education")
        {
            art_emphasis = emphasis;
        }
        else
        {
            std::cout << "Invalid art emphasis. Value unchanged.\n";
        }
    }

    std::string getArtEmphasis() const
    {
        return art_emphasis;
    }
};

// Physics students have an extra concentration field.
class Physics_Student : public Student
{
private:
    std::string concentration;

public:
    Physics_Student()
    {
        concentration = "Biophysics";
    }

    ~Physics_Student()
    {
    }

    void setConcentration(std::string value)
    {
        // Only allow these two choices.
        if (value == "Biophysics" ||
            value == "Earth and Planetary Sciences")
        {
            concentration = value;
        }
        else
        {
            std::cout << "Invalid concentration. Value unchanged.\n";
        }
    }

    std::string getConcentration() const
    {
        return concentration;
    }
};

int main()
{
    // Open the file first.
    std::ofstream outfile("student_info.dat");

    if (!outfile)
    {
        std::cout << "Could not open student_info.dat.\n";
        return 1;
    }

    std::vector<Art_Student *> art_students;
    std::vector<Physics_Student *> physics_students;

    // Sample info for the art students.
    std::string art_first[5] =
        {"Maya", "Alex", "Elias", "Sammy", "Taylor"};

    std::string art_last[5] =
        {"G.", "M.", "G.", "Y.", "L."};

    std::string art_gpa[5] =
        {"3.2", "3.5", "3.4", "3.1", "2.7"};

    std::string emphases[5] =
    {
        "Art Studio",
        "Art History",
        "Art Education",
        "Art Studio",
        "Art History"
    };

    // Sample info for the physics students.
    std::string physics_first[5] =
        {"Thomas", "David", "Aiden", "Daniel", "Link"};

    std::string physics_last[5] =
        {"G.", "J.", "Z.", "W.", "S."};

    std::string physics_gpa[5] =
        {"3.7", "3.4", "3.3", "3.6", "3.2"};

    std::string concentrations[5] =
    {
        "Biophysics",
        "Earth and Planetary Sciences",
        "Biophysics",
        "Earth and Planetary Sciences",
        "Biophysics"
    };

    // Make five art students and fill in their info.
    for (int i = 0; i < 5; i++)
    {
        art_students.push_back(new Art_Student);

        art_students[i]->setName(art_first[i], art_last[i]);
        art_students[i]->setGPA(art_gpa[i]);

        art_students[i]->setGraduationYear(2027);
        art_students[i]->setGraduationSemester("Spring");

        art_students[i]->setEnrolledYear(2023);
        art_students[i]->setEnrolledSemester("Fall");

        art_students[i]->setStudentLevel("Undergraduate");
        art_students[i]->setArtEmphasis(emphases[i]);
    }

    // Make five physics students and fill in their info.
    for (int i = 0; i < 5; i++)
    {
        physics_students.push_back(new Physics_Student);

        physics_students[i]->setName(
            physics_first[i], physics_last[i]);

        physics_students[i]->setGPA(physics_gpa[i]);

        physics_students[i]->setGraduationYear(2028);
        physics_students[i]->setGraduationSemester("Fall");

        physics_students[i]->setEnrolledSemester("Fall");

        if (i < 3)
        {
            physics_students[i]->setEnrolledYear(2024);
            physics_students[i]->setStudentLevel("Undergraduate");
        }
        else
        {
            physics_students[i]->setEnrolledYear(2026);
            physics_students[i]->setStudentLevel("Graduate");
        }

        physics_students[i]->setConcentration(concentrations[i]);
    }

    outfile << "STUDENT INFORMATION\n";
    outfile << "===================\n\n";

    // Write all the art students.
    for (std::size_t i = 0; i < art_students.size(); i++)
    {
        outfile << "Program: Art\n";

        outfile << "Name: "
                << art_students[i]->getFirstName() << " "
                << art_students[i]->getLastName() << "\n";

        outfile << "GPA: "
                << art_students[i]->getGPA() << "\n";

        outfile << "Graduation: "
                << art_students[i]->getGraduationSemester() << " "
                << art_students[i]->getGraduationYear() << "\n";

        outfile << "Enrolled: "
                << art_students[i]->getEnrolledSemester() << " "
                << art_students[i]->getEnrolledYear() << "\n";

        outfile << "Student level: "
                << art_students[i]->getStudentLevel() << "\n";

        outfile << "Art emphasis: "
                << art_students[i]->getArtEmphasis() << "\n\n";
    }

    // Write all the physics students to the same file.
    for (std::size_t i = 0; i < physics_students.size(); i++)
    {
        outfile << "Program: Physics\n";

        outfile << "Name: "
                << physics_students[i]->getFirstName() << " "
                << physics_students[i]->getLastName() << "\n";

        outfile << "GPA: "
                << physics_students[i]->getGPA() << "\n";

        outfile << "Graduation: "
                << physics_students[i]->getGraduationSemester() << " "
                << physics_students[i]->getGraduationYear() << "\n";

        outfile << "Enrolled: "
                << physics_students[i]->getEnrolledSemester() << " "
                << physics_students[i]->getEnrolledYear() << "\n";

        outfile << "Student level: "
                << physics_students[i]->getStudentLevel() << "\n";

        outfile << "Concentration: "
                << physics_students[i]->getConcentration() << "\n\n";
    }

    outfile.close();
    bool write_failed = !outfile;

    // Delete the students we made with new.
    for (std::size_t i = 0; i < art_students.size(); i++)
    {
        delete art_students[i];
    }

    for (std::size_t i = 0; i < physics_students.size(); i++)
    {
        delete physics_students[i];
    }

    // Remove the old addresses from the vectors.
    art_students.clear();
    physics_students.clear();

    if (write_failed)
    {
        std::cout << "There was a problem writing the file.\n";
        return 1;
    }

    std::cout << "Saved 10 students to student_info.dat.\n";

    return 0;
}
