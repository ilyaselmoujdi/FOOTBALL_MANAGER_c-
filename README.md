# FOOTBALL_MANAGER.cpp
 Project Overview
The Football Team Management System is a comprehensive C++ console application designed to efficiently manage football team rosters. This project demonstrates professional software development practices including Object-Oriented Programming (OOP), data validation, STL algorithms, and modular code organization.
Built with simplicity and functionality in mind, this system provides team managers with powerful tools to organize, search, and analyze player data—all through an intuitive menu-driven interface.

⚽ What Does It Do?
This application serves as a digital team management solution, replacing traditional paper-based record-keeping with a robust, automated system. Whether you're managing a local club or tracking your fantasy team, this program handles all aspects of roster management efficiently.
The system manages up to 40 players simultaneously and comes pre-loaded with 20 famous football players (including Messi, Ronaldo, Mbappe, and more) for immediate testing and exploration.

✨ Key Features
1. Complete Player Management (CRUD Operations)

Add Players: Register new players with comprehensive information (name, age, shirt number, position, goals, registration date, and status)
Modify Players: Update existing player information (position, age, goals)
Remove Players: Delete players from the roster
Batch Addition: Add multiple players in one session for efficient team setup

2. Advanced Display & Sorting (5 Options)

Sort by Name: Alphabetical ordering (A-Z)
Sort by Age: Youngest to oldest
Filter by Position: View only Goalkeepers, Defenders, Midfielders, or Strikers
Filter by Status: Separate Starters from Substitutes
Filter by Age Range: Display players within specific age brackets

3. Dual Search Functionality

Search by ID: Fast, precise player lookup using unique identifier
Search by Name: User-friendly search using player's full name
Instant results with goal statistics

4. Team Statistics & Analytics

Total Player Count: Current roster size and capacity tracking
Average Age: Team age distribution analysis
Top Scorer: Automatic identification of highest goal scorer
Age Extremes: Find youngest and oldest players

5. Automatic Star Player Detection ⭐

Players with 10 or more goals are automatically promoted to "Star" status
Visual distinction with star emoji (⭐) in player listings
Real-time notifications when players achieve star status
Recognition system runs before every menu display

6. Robust Data Validation

Name Validation: Prevents numeric characters in names
Age Validation: Restricts ages to realistic range (15-50 years)
Unique Shirt Numbers: Prevents duplicate jersey numbers
Date Validation: Ensures valid dates in correct format (dd/mm/yyyy, 1999-2025)
Capacity Management: Prevents exceeding 40-player limit
User-friendly error messages guide corrections

7. Professional User Interface

Color-Coded Messages: Green for success, red for errors, cyan for prompts, blue for menus
Menu-Driven Navigation: Clear 8-option main menu
Formatted Output: Consistent, readable player information display
Progress Indicators: Shows batch operation progress

8. Build Automation

Makefile Included: One-command compilation and execution
Commands: make (compile), make run (compile & run), make clean (remove compiled files)
Professional build system for easy deployment
Technical Highlights
Technologies & Concepts Used:

C++ Programming Language (C++11 standard)
Object-Oriented Programming (OOP): Classes, encapsulation, constructors
STL (Standard Template Library):

vector for dynamic player storage
sort() for flexible ordering
max_element() / min_element() for statistics
find_if() for searching


Lambda Functions: Custom sorting comparators
Input Validation: Do-while loops with validation functions
ANSI Color Codes: Enhanced terminal output
Modular Design: Separation of header and implementation files

📁 Project Root
├── Player.h          # Player class declaration
├── Player.cpp        # Player class implementation
├── Team.h           # Team class declaration
├── Team.cpp         # Team class implementation (core logic)
├── main.cpp         # Program entry point and menu system
└── Makefile         # Build automation script
How to Use
Upon starting, the program loads 20 test players and displays the main menu with 8 options:

Add a player - Register new player with full details
Add multiple players - Batch registration for multiple players
Display all players - View roster with 5 sorting/filtering options
Modify a player - Update existing player information
Remove a player - Delete player from roster
Search for a player - Find by ID or name
Statistics - View team analytics (count, average age, top scorer, age extremes)
Exit - Close the program

Simply enter the number corresponding to your desired action and follow the prompts.

 Use Cases

Sports Team Management: Track real football/soccer team rosters
Educational Tool: Learn C++ OOP, STL, and data structures
Fantasy League: Manage fantasy football teams
Demonstration Project: Showcase programming skills in portfolio
Foundation for Expansion: Base system for more complex sports management applications


Learning Outcomes
This project demonstrates proficiency in:

Designing and implementing complete OOP systems
Managing dynamic data structures (vectors)
Implementing robust input validation
Using STL algorithms effectively
Creating user-friendly interfaces
Writing maintainable, modular code
Automating build processes
Problem-solving and software architecture


Future Enhancement Possibilities

Data Persistence: Save/load team data to/from files (CSV, JSON, binary)
Database Integration: Connect to MySQL or SQLite for permanent storage
Graphical User Interface: Develop GUI using Qt or wxWidgets
Advanced Statistics: Performance trends, injury tracking, match history
Multi-Team Support: Manage multiple teams simultaneously
Web Interface: Create REST API with web frontend
Export Functionality: Generate reports in PDF or Excel format
Player Transfer System: Trade players between teams
Match Simulator: Simulate games and update statistics

Authors:

Ilyas El Moujdi
Youssef Asnaoui

Email: ilyaselmoujdi@gmail.com
       Youssefasnaoui7@gmail.com
  


