#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cctype>

using namespace std;


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

     

        branch=DEPARTMENTS[branchChoice-1];

        cout<<"\nEnter SGPA : ";

        while(!(cin>>sgpa)
        || sgpa<0

        || sgpa>10)


        
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
        compChoice<=COMPANY_DIRECTORY.size()){
        {
            dreamCompany=COMPANY_DIRECTORY[compChoice-1].name;        }


        }

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
// =========================================================================================
// JOB ROLE STRUCTURE
// =========================================================================================

struct JobRole {
    string roleName;
    float minSgpa;
    float roleRating;
    vector<int> skillReqs;
    vector<string> eligibleBranches;

    JobRole(string name,
            float gpa,
            float rating,
            vector<int> reqs,
            vector<string> branches)
        : roleName(name),
          minSgpa(gpa),
          roleRating(rating),
          skillReqs(reqs),
          eligibleBranches(branches) {}
};

// =========================================================================================
// BASE COMPANY CLASS
// =========================================================================================

class Company {
protected:
    string companyName;
    float companyRating;
    vector<JobRole> roles;

public:
    virtual ~Company() {}

    string getCompanyName() const {
        return companyName;
    }

    float getCompanyRating() const {
        return companyRating;
    }

    void matchAndAnalyze(const Student& s);
};

// =========================================================================================
// GOOGLE
// =========================================================================================

class Google : public Company {
public:
    Google() {
        companyName = "Google";
        companyRating = 9.8f;

        vector<int> sdeReq = {
            9,9,7,6,4,8,8,7,9,6,
            5,0,0,7,9,8,7,8,6,7,
            0,0,0,8,10
        };

        roles.push_back(JobRole(
    "Software Engineer III",
    8.5,
    9.7,
    sdeReq,
    {"CSE","IT","ECE"}   
));

        vector<int> mlReq = {
            7,6,10,0,0,6,6,5,7,6,
            0,0,0,7,8,7,7,9,7,10,
            8,0,0,7,9
        };

        roles.push_back(JobRole(
            "AI/ML Researcher",
            9.0,
            9.9,
            mlReq,
            {"CSE","IT"}
        ));
    }
};

// =========================================================================================
// AMAZON
// =========================================================================================

class Amazon : public Company {
public:
    Amazon() {

        companyName = "Amazon";
        companyRating = 9.2f;

        vector<int> sdeReq = {
            10,8,7,7,5,8,7,6,9,7,
            6,0,0,8,9,8,6,7,7,6,
            5,0,0,8,9
        };

        roles.push_back(JobRole(
            "SDE-1 (New Grad)",
            7.5,
            8.8,
            sdeReq,
            {"CSE","IT","ECE","EEE"}
        ));

        vector<int> cloudReq = {
            6,6,7,0,0,7,8,9,7,7,
            0,0,0,7,8,8,8,10,9,6,
            7,0,0,7,8
        };

        roles.push_back(JobRole(
            "Cloud Support Architect",
            7.0,
            8.5,
            cloudReq,
            {"CSE","IT","ECE","EEE","MECH"}
        ));
    }
};

// =========================================================================================
// MICROSOFT
// =========================================================================================

class Microsoft : public Company {
public:

    Microsoft() {

        companyName = "Microsoft";
        companyRating = 9.5f;

        vector<int> sweReq = {
            9,8,7,6,0,8,8,7,8,7,
            5,0,0,7,9,8,7,7,6,7,
            0,0,0,9,9
        };

        roles.push_back(JobRole(
            "Software Engineer",
            8.0,
            9.4,
            sweReq,
            {"CSE","IT","ECE"}
        ));

        vector<int> dsReq = {
            7,5,10,0,0,8,5,5,7,7,
            0,0,0,9,8,7,6,7,6,9,
            9,0,0,8,8
        };

        roles.push_back(JobRole(
            "Data Scientist",
            8.5,
            9.2,
            dsReq,
            {"CSE","IT"}
        ));
    }
};

// =========================================================================================
// SAP
// =========================================================================================

class SAP : public Company {
public:
    SAP() {
        companyName = "SAP";
        companyRating = 8.9f;

        vector<int> devReq = {
            8,7,6,9,6,8,7,6,9,7,
            8,0,0,9,7,7,6,8,5,6,
            0,0,0,8,8
        };

        roles.push_back(JobRole(
            "Developer Associate",
            7.5,
            8.5,
            devReq,
            {"CSE","IT","ECE"}
        ));

        vector<int> consReq = {
            5,4,6,0,0,7,0,0,6,9,
            0,0,0,8,6,6,5,6,0,0,
            0,0,0,10,9
        };

        roles.push_back(JobRole(
            "Technical Consultant",
            7.0,
            8.0,
            consReq,
            {"CSE","IT","ECE","EEE","MECH","CIVIL"}
        ));
    }
};

// =========================================================================================
// BLACKROCK
// =========================================================================================

class BlackRock : public Company {
public:
    BlackRock() {
        companyName = "BlackRock";
        companyRating = 9.4f;

        vector<int> finReq = {
            8,7,8,8,0,9,0,0,8,9,
            0,0,0,9,8,7,6,7,0,7,
            9,0,0,9,10
        };

        roles.push_back(JobRole(
            "Aladdin Wealth Tech Analyst",
            8.0,
            9.3,
            finReq,
            {"CSE","IT","ECE","EEE"}
        ));

        vector<int> qaReq = {
            7,7,6,0,0,7,6,6,7,8,
            6,5,5,7,6,8,6,6,0,5,
            0,0,0,8,7
        };

        roles.push_back(JobRole(
            "Quality Assurance Engineer",
            7.0,
            8.2,
            qaReq,
            {"CSE","IT","ECE"}
        ));
    }
};

// =========================================================================================
// ATLASSIAN
// =========================================================================================

class Atlassian : public Company {
public:
    Atlassian() {
        companyName = "Atlassian";
        companyRating = 9.7f;

        vector<int> beReq = {
            10,8,7,8,0,9,8,7,10,8,
            0,0,0,9,10,9,8,8,7,6,
            0,0,0,9,10
        };

        roles.push_back(JobRole(
            "Backend Engineer (Jira Core)",
            8.5,
            9.8,
            beReq,
            {"CSE","IT"}
        ));

        vector<int> feReq = {
            7,5,0,0,10,6,0,0,8,7,
            10,10,9,7,8,8,5,7,0,0,
            0,0,0,8,9
        };

        roles.push_back(JobRole(
            "Frontend Architect", 
            8.0,
            9.5,
            feReq,
            {"CSE","IT"}
        ));
    }
};

// =========================================================================================
// TCS
// =========================================================================================

class TCS : public Company {
public:
    TCS() {
        companyName = "TCS";
        companyRating = 7.5f;

        vector<int> ninjaReq = {
            5,5,5,5,3,5,4,4,5,8,
            3,0,0,5,0,5,4,4,0,0,
            0,0,0,7,7
        };

        roles.push_back(JobRole(
            "TCS Ninja",
            6.0,
            6.8,
            ninjaReq,
            {"CSE","IT","ECE","EEE","MECH","CIVIL","BIOTECH"}
        ));

        vector<int> digitalReq = {
            7,7,7,7,5,7,7,7,7,9,
            6,5,5,7,6,7,6,6,5,5,
            5,0,0,8,8
        };

        roles.push_back(JobRole(
            "TCS Digital",
            7.0,
            7.8,
            digitalReq,
            {"CSE","IT","ECE","EEE"}
        ));
    }
};

// =========================================================================================
// ORACLE
// =========================================================================================

class Oracle : public Company {
public:
    Oracle() {
        companyName = "Oracle";
        companyRating = 9.0f;

        vector<int> devReq = {
            8,7,7,7,4,9,7,6,8,6,
            5,0,0,10,8,7,6,7,5,6,
            0,0,0,7,9
        };

        roles.push_back(JobRole(
            "Software Developer",
            7.5,
            8.7,
            devReq,
            {"CSE","IT","ECE"}
        ));

        vector<int> dbReq = {
            6,6,7,0,0,9,6,5,7,6,
            0,0,0,10,7,6,5,6,0,0,
            0,0,0,7,8
        };

roles.push_back(JobRole(
    "Database Engineer",
    7.0,
    8.3,
    dbReq,      
    {"CSE","IT"}
));
    }
};

// =========================================================================================
// DELOITTE
// =========================================================================================

class Deloitte : public Company {
public:
    Deloitte() {
        companyName = "Deloitte";
        companyRating = 8.7f;

        vector<int> consReq = {
            5,5,5,5,4,7,0,0,6,9,
            0,0,0,8,6,6,5,6,0,0,
            0,0,0,10,9
        };

        roles.push_back(JobRole(
            "Technical Consultant",
            7.0,
            8.0,
            consReq,
            {"CSE","IT","ECE","EEE","MECH","CIVIL"}
        ));

        vector<int> analystReq = {
            4,4,5,0,0,6,0,0,5,9,
            0,0,0,6,5,5,4,4,0,0,
            0,0,0,10,10
        };

        roles.push_back(JobRole(
            "Business Analyst",
            6.5,
            7.8,
            analystReq,
            {"CSE","IT","ECE","EEE","MECH","CIVIL","CHEMICAL","BIOTECH"} 
        ));
    }
};

// =========================================================================================
// GOLDMAN SACHS
// =========================================================================================

class GoldmanSachs : public Company {
public:
    GoldmanSachs() {
        companyName = "Goldman Sachs";
        companyRating = 9.6f;

        vector<int> finReq = {
            9,8,8,8,0,9,0,0,9,9,
            0,0,0,9,8,8,7,7,0,7,
            9,0,0,9,10
        };

        roles.push_back(JobRole(
            "Software Engineer (Finance Tech)",
            8.5,
            9.5,
            finReq,
            {"CSE","IT","ECE","EEE"}
        ));
    }
};

// =========================================================================================
// INFOSYS
// =========================================================================================

class Infosys : public Company {
public:
    Infosys() {
        companyName = "Infosys";
        companyRating = 7.5f;

        vector<int> sysReq = {
            5,5,5,5,3,5,4,4,5,8,
            3,0,0,5,0,5,4,4,0,0,
            0,0,0,7,7
        };

        roles.push_back(JobRole(
            "System Engineer",
            6.0,
            6.8,
            sysReq,
            {"CSE","IT","ECE","EEE","MECH","CIVIL"}
        ));
    }
};

// =========================================================================================
// WIPRO
// =========================================================================================

class Wipro : public Company {
public:
    Wipro() {
        companyName = "Wipro";
        companyRating = 7.4f;

        vector<int> projReq = {
            5,5,5,5,3,5,4,4,5,7,
            3,0,0,5,0,5,4,4,0,0,
            0,0,0,7,7
        };

        roles.push_back(JobRole(
            "Project Engineer",
            6.0,
            6.5,
            projReq,
            {"CSE","IT","ECE","EEE","MECH","CIVIL"}
        ));
    }
};

// =========================================================================================
// ACCENTURE
// =========================================================================================

class Accenture : public Company {
public:
    Accenture() {
        companyName = "Accenture";
        companyRating = 8.2f;

        vector<int> aseReq = {
            6,6,6,6,5,6,5,5,6,8,
            5,0,0,6,5,6,5,5,0,0,
            0,0,0,8,8
        };

        roles.push_back(JobRole(
            "Associate Software Engineer",
            6.5,
            7.5,
            aseReq,
            {"CSE","IT","ECE","EEE","MECH","CIVIL"}
        ));
    }
};





// =========================================================================================
// PLACEMENT MATCHING & SKILL GAP ANALYSIS
// =========================================================================================

void Company::matchAndAnalyze(const Student& s)
{
    bool anyRoleFound = false;

    cout << "\n--- Processing Application for "
         << companyName
         << " [" << companyRating << "/10] ---\n";

    for (const auto& job : roles)
    {
        bool branchEligible = false;

        // ---------------- Branch Eligibility ----------------

        for (const string& b : job.eligibleBranches)
        {
            if (b == s.getBranch())
            {
                branchEligible = true;
                break;
            }
        }

        if (!branchEligible)
            continue;

        // ---------------- SGPA Eligibility ----------------

        if (s.getSgpa() < job.minSgpa)
            continue;

        anyRoleFound = true;

        // ---------------- Skill Matching ----------------

        float matchedSkills = 0;
        float totalRequiredSkills = 0;

        vector<string> missingSkills;
        vector<string> strongSkills;

        for (size_t i = 0; i < SKILL_BOOK.size(); i++)
        {
            if (job.skillReqs[i] > 0)
            {
                totalRequiredSkills++;

                if (s.hasSkill(i) &&
                    s.getRating(i) >= job.skillReqs[i])
                {
                    matchedSkills++;

                    // Student is significantly better than requirement
                    if (s.getRating(i) >= job.skillReqs[i] + 2)
                    {
                        strongSkills.push_back(SKILL_BOOK[i]);
                    }
                }
                else
                {
                    missingSkills.push_back(SKILL_BOOK[i]);
                }
            }
        }

        // ---------------- Match Percentage ----------------

        float finalPercent = 0.0f;

        if (totalRequiredSkills > 0)
        {
            finalPercent =
                (matchedSkills / totalRequiredSkills) * 100.0f;
        }

        cout << "\nRole : "
             << job.roleName
             << " (Rating : "
             << job.roleRating
             << "/10)\n";

        cout << "Match Percentage : "
             << fixed
             << setprecision(2)
             << finalPercent
             << "%\n";

        // ---------------- Verdict ----------------

        if (finalPercent >= 85)
        {
            cout << "Verdict : Highly Compatible\n";
            cout << "Selection Probability : High\n";
            cout << "Predicted Round : Final Interview\n";
        }
        else if (finalPercent >= 60)
        {
            cout << "Verdict : Moderate Match\n";
            cout << "Selection Probability : Medium\n";
            cout << "Recommendation : Brush up on core skills\n";
        }
        else
        {
            cout << "Verdict : Low Match\n";
            cout << "Selection Probability : Low\n";
            cout << "Recommendation : Significant preparation required\n";
        }

        // ---------------- Strong Skills ----------------

        if (!strongSkills.empty())
        {
            cout << "Strong Skills : ";

            for (size_t i = 0; i < strongSkills.size(); i++)
            {
                cout << strongSkills[i];

                if (i != strongSkills.size() - 1)
                    cout << ", ";
            }

            cout << endl;
        }

        // ---------------- Skill Gap Analysis ----------------

        if (!missingSkills.empty())
        {
            cout << "Critical Skill Gaps : ";

            for (size_t i = 0; i < missingSkills.size(); i++)
            {
                cout << missingSkills[i];

                if (i != missingSkills.size() - 1)
                    cout << ", ";
            }

            cout << endl;
        }

        cout << "-------------------------------------------------\n";
    }

    // ---------------- No Eligible Role ----------------

    if (!anyRoleFound)
    {
        cout << "\nSorry! You do not satisfy the minimum "
                << "eligibility criteria for any role in "
                << companyName
                << ".\n";
             
    }

    cout << "=================================================\n";
}
// =========================================================================================
//                           PACKAGE PREDICTION MODULE
// =========================================================================================

float predictPackage(const Student& s)
{
    float totalSkillScore = 0;
    int skillCount = 0;

    for (size_t i = 0; i < SKILL_BOOK.size(); i++)
    {
        if (s.hasSkill(i))
        {
            totalSkillScore += s.getRating(i);
            skillCount++;
        }
    }

    float avgSkill = (skillCount > 0) ? totalSkillScore / skillCount : 0;
    float overallScore = (s.getSgpa() * 10 + avgSkill * 10) / 2;

    if (overallScore >= 90)
        return 40.0f;
    else if (overallScore >= 80)
        return 25.0f;
    else if (overallScore >= 70)
        return 18.0f;
    else if (overallScore >= 60)
        return 12.0f;
    else if (overallScore >= 50)
        return 8.0f;

    return 4.0f;
}

// =========================================================================================
// STUDENT PROFILE SUMMARY
// =========================================================================================

void generateStudentReport(const Student& s)
{
    cout << "\n\n";
    cout << "=========================================================\n";
    cout << "              STUDENT PROFILE SUMMARY\n";
    cout << "=========================================================\n";

    cout << "Name           : " << s.getName() << endl;
    cout << "Branch         : " << s.getBranch() << endl;
    cout << "SGPA           : " << s.getSgpa() << endl;
    cout << "Dream Company  : " << s.getDreamCompany() << endl;
    cout << "Dream Role     : " << s.getDreamRole() << endl; 

    cout << "\nSkills Entered\n\n";

    bool found = false;

    for (size_t i = 0; i < SKILL_BOOK.size(); i++)
    {
        if (s.hasSkill(i))
        {
            found = true;

            cout << "- "
                 << setw(20)
                 << left
                 << SKILL_BOOK[i]
                 << " Rating : "
                 << s.getRating(i)
                 << endl;
        }
    }

    
    if (!found) 
    {
        cout << "No skills entered.\n";
    }

    cout << "=========================================================\n";
}

// DREAM COMPANY ANALYSIS
// =========================================================================================

void analyzeDreamCompany(
    const Student& student,
    const vector<Company*>& companies)
{
    cout << "\n\n";
    cout << "=========================================================\n";
    cout << "             DREAM COMPANY ANALYSIS\n";
    cout << "=========================================================\n";

    bool found = false;

    for (const auto& company : companies)
    {
        
        if (company->getCompanyName() ==
            student.getDreamCompany())
        {
            found = true;

            cout << "\nTarget Company : "
                 << student.getDreamCompany()
                 << endl;

            cout << "Target Role    : "
                 << student.getDreamRole()
                 << endl;

            company->matchAndAnalyze(student);

            break;
        }
    }

    
    if (!found)
    {
        cout << "Dream company not present in database.\n";
    }
}


// =========================================================================================
// MAIN FUNCTION
// =========================================================================================

int main()
{
    
    Student student;

    
    student.collectProfileData();

   
    vector<Company*> companies;

    companies.push_back(new Google());
    companies.push_back(new Amazon());
    companies.push_back(new Microsoft());
    companies.push_back(new SAP());
    companies.push_back(new BlackRock());
    companies.push_back(new Atlassian());
    companies.push_back(new TCS());
    companies.push_back(new Oracle());
    companies.push_back(new Deloitte());
    companies.push_back(new GoldmanSachs());
    companies.push_back(new Infosys());
    companies.push_back(new Wipro());
    companies.push_back(new Accenture());

    
    generateStudentReport(student);

    cout << "\n\n";
    cout << "=========================================================\n";
    cout << "         COMPANY MATCHING ANALYSIS REPORT\n";
    cout << "=========================================================\n";

    
    for (auto company : companies)
    {
        company->matchAndAnalyze(student);
    }

    
    analyzeDreamCompany(student, companies);

    cout << "\n\n";
    cout << "=========================================================\n";
    cout << "           PACKAGE PREDICTION ENGINE\n";
    cout << "=========================================================\n";

    // Predict Package
    float predictedPackage = predictPackage(student);

    
    cout << "\nEstimated Placement Package : "
         << fixed
         << setprecision(2)
         << predictedPackage
         <<" LPA\n";

    cout << "\n=========================================================\n";
    cout << "    THANK YOU FOR USING T&P CELL MANAGEMENT SYSTEM\n";
    cout << "=========================================================\n";

    
    for (auto company : companies)
    {
        
        
        delete company;
    }

    return 0;
}