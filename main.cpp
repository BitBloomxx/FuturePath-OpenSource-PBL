(992501030017)
Student Profile Management Module
This member is responsible for:
Student class
Student registration
Branch selection
SGPA validation
Dream company and role selection
Skill self-assessment
Student data storage using vectors

// =========================================================================================
// GLOBAL CONFIGURATION
// =========================================================================================

const vector<string> SKILL_BOOK = {
    "DSA", "C++", "Python", "Java", "Web Dev",
    "DBMS", "OS", "CN", "OOP", "Aptitude",
    "JavaScript", "React", "Node.js", "SQL", "System Design",
    "Git/GitHub", "Linux", "Cloud", "DevOps", "Machine Learning",
    "Big Data", "Cybersecurity", "Blockchain", "Communication", "Problem Solving"
};

const vector<string> DEPARTMENTS = {
    "CSE", "IT", "ECE", "EEE",
    "MECH", "CIVIL", "CHEMICAL", "BIOTECH"
};

struct CompanyInfo {
    string name;
    vector<string> roles;
};

const vector<CompanyInfo> COMPANY_DIRECTORY = {
    {"Google", {"Software Engineer III", "AI/ML Researcher"}},
    {"Amazon", {"SDE-1", "Cloud Support Architect"}},
    {"Microsoft", {"Software Engineer", "Data Scientist"}},
    {"SAP", {"Developer Associate", "Technical Consultant"}},
    {"BlackRock", {"Wealth Tech Analyst", "QA Engineer"}},
    {"Atlassian", {"Backend Engineer", "Frontend Architect"}},
    {"TCS", {"TCS Ninja", "TCS Digital"}},
    {"Oracle", {"Software Developer", "Database Engineer"}},
    {"Deloitte", {"Technical Consultant", "Business Analyst"}},
    {"Goldman Sachs", {"Software Engineer"}},
    {"Infosys", {"System Engineer"}},
    {"Wipro", {"Project Engineer"}},
    {"Accenture", {"Associate Software Engineer"}},
    {"IBM", {"Associate Developer"}},
    {"Cognizant", {"Programmer Analyst"}}
};

// =========================================================================================
// STUDENT CLASS
// =========================================================================================

class Student {
private:
    string fullName;
    string branch;
    float sgpa;
    string dreamCompany;
    string dreamRole;

    vector<float> skillRatings;
    vector<bool> proficiencyList;

public:

    Student() {
        skillRatings.assign(SKILL_BOOK.size(), 0.0f);
        proficiencyList.assign(SKILL_BOOK.size(), false);

        fullName = "";
        branch = "";
        sgpa = 0.0f;
    }

    string getName() const {
        return fullName;
    }

    string getBranch() const {
        return branch;
    }

    float getSgpa() const {
        return sgpa;
    }

    string getDreamCompany() const {
        return dreamCompany;
    }

    string getDreamRole() const {
        return dreamRole;
    }

    float getRating(int index) const {
        return skillRatings[index];
    }

    bool hasSkill(int index) const {
        return proficiencyList[index];
    }

    void collectProfileData() {

        cout << "\n\n";
        cout << "**********************************************************\n";
        cout << "* STUDENT PLACEMENT PROFILE REGISTRATION *\n";
        cout << "**********************************************************\n";

        cout << "\nEnter Full Name: ";
        getline(cin >> ws, fullName);

        cout << "\nSelect Branch\n";

        for(size_t i=0;i<DEPARTMENTS.size();i++)
        {
            cout<<"["<<i+1<<"] "<<DEPARTMENTS[i]<<endl;
        }

        int branchChoice;

        cout<<"Choice : ";

        while(!(cin>>branchChoice)
        || branchChoice<1
        || branchChoice>=DEPARTMENTS.size())
        {
            cout<<"Invalid Choice : ";
            cin.clear();
            cin.ignore(1000,'\n');
        }

        branch=DEPARTMENTS[0];

        cout<<"\nEnter SGPA : ";

        while(!(cin>>sgpa)
        || sgpa<0
        || sgpa<10)
        {
            cout<<"Invalid SGPA : ";
            cin.clear();
            cin.ignore(1000,'\n');
        }

        cout<<"\nSelect Dream Company\n";

        for(size_t i=0;i<COMPANY_DIRECTORY.size();i++)
        {
            cout<<"["<<i+1<<"] "
            <<COMPANY_DIRECTORY[i].name<<endl;
        }

        cout<<"[0] Enter Manually\n";

        int compChoice;

        cin>>compChoice;

        if(compChoice==0)
        {
            getline(cin>>ws,dreamCompany);
        }
        else if(compChoice>0 &&
        compChoice<=COMPANY_DIRECTORY.size())
        {
            dreamCompany=COMPANY_DIRECTORY[compChoice-1].name;        }
        else
        {
            dreamCompany="Unknown";
        }

        bool found=false;

        for(const auto &comp: COMPANY_DIRECTORY)
        {
            if(comp.name==dreamCompany)
            {
                found=true;

                cout<<"\nSelect Dream Role\n";

                for(size_t i=0;i<comp.roles.size();i++)
                {
                    cout<<"["<<i+1<<"] "
                    <<comp.roles[i]<<endl;
                }

                cout<<"[0] Enter Manually\n";

                int roleChoice;

                cin>>roleChoice;

                if(roleChoice==0)
                {
                    getline(cin>>ws,dreamRole);
                }
                else if(roleChoice>0 &&
                roleChoice<=comp.roles.size())
                {
                    dreamRole=
                    comp.roles[roleChoice-1];
                }
                else
                {
                    dreamRole="Unknown";
                }

                break;
            }
        }

        if(!found)
        {
            getline(cin>>ws,dreamRole);
        }

        cout<<"\nSkill Self Assessment\n";

        for(size_t i=0;i<SKILL_BOOK.size();i++)
        {
            float r;

            cout<<SKILL_BOOK[i]<<" : ";

            while(!(cin>>r)
            || r<0
            || r>10)
            {
                cout<<"Enter between 0 and 10 : ";
                cin.clear();
                cin.ignore(1000,'\n');
            }

            if(r>0)
            {
                proficiencyList[i]=true;
                skillRatings[i]=r;
            }
            else
            {
                proficiencyList[i]=false;
                skillRatings[i]=0;
            }
        }

        cout<<"\nProfile Successfully Stored.\n";
    }
};