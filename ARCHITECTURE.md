```text
+-------------------------------------------------------------------------+
|                          USER INTERACTION LAYER                         |
|   - Standard Input / Output (std::cin, std::cout)                       |
|   - Formatted Reporting (std::setw, std::fixed)                         |
+-------------------------------------------------------------------------+
                                     |
                                     v
+------------------------------------+------------------------------------+
|                         CORE DATA STRUCTURES                            |
|                                                                         |
|   +----------------------------+       +----------------------------+   |
|   |       class Student        |       |       struct JobRole       |   |
|   +----------------------------+       +----------------------------+   |
|   | - fullName: string         |       | - roleName: string         |   |
|   | - branch: string           |       | - minSgpa: float           |   |
|   | - sgpa: float              |       | - roleRating: float        |   |
|   | - dreamCompany: string     |       | - skillReqs: vector<int>   |   |
|   | - dreamRole: string        |       | - eligibleBranches: strings|   |
|   | - skillRatings: vector     |       +----------------------------+   |
|   | - proficiencyList: vector  |                                        |
|   +----------------------------+                                        |
+------------------------------------+------------------------------------+
                                     |
                                     v
+------------------------------------+------------------------------------+
|                      PROCESSING & ENGINE LAYER                          |
|                                                                         |
|    +---------------------------------------------------------------+    |
|    |               Polymorphic Company Subsystem                   |    |
|    |                                                               |    |
|    |                    [ abstract Company ]                       |    |
|    |                             |                                 |    |
|    |      +----------------------+----------------------+          |    |
|    |      |                      |                      |          |    |
|    |  v---v----+             v---v----+             v---v----+     |    |
|    |  | Google |             | Amazon |             |  ...   |     |    |
|    |  +--------+             +--------+             +--------+     |    |
|    |  (sdeReq, mlReq)        (sde1Req, cloudReq)                   |    |
|    +---------------------------------------------------------------+    |
|                                    |                                    |
|                                    v                                    |
|    +---------------------------------------------------------------+    |
|    |                     Business Logic Engines                    |    |
|    |                                                               |    |
|    |   * matchAndAnalyze()      ->  Evaluates eligibility gaps     |    |
|    |   * predictPackage()       ->  Computes average skill vs GPA  |    |
|    |   * analyzeDreamCompany()  ->  Filters targeted aspirations    |    |
|    +---------------------------------------------------------------+    |
+------------------------------------+------------------------------------+
                                     |
                                     v
+------------------------------------+------------------------------------+
|                          OUTPUT REPORT GENERATION                       |
|   1. Student Profile Summary                                            |
|   2. Comprehensive Company Matching Matrix                              |
|   3. Targeted Dream Company Gap Analysis                                |
|   4. Predicted Package Estimation (LPA)                                 |
+-------------------------------------------------------------------------+
