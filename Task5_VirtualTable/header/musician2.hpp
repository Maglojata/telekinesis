#include <iostream>

struct Musician;
struct String;
struct Brass; 
struct Violin;
struct Guitar;
struct Piano;
struct Flute;
struct Trumpet; 
struct Trumbone;
struct Clarinet; 


//type info
struct musTI {
    std::string name = "Musician";
    std::string base{};
} musti;

//virtual table
struct MusVtbl {
    musTI* ti = &musti;
	void (Musician::* fplay)();
//  void (Musician::* fplay)() = &Musician::play;
} musvtbl;

struct Musician {
    void play() {
        std::cout << "play" << std::endl;
    }
    MusVtbl* vptr = &musvtbl;
};


//type info
struct strTI {
    std::string name = "String";
    std::string base[1] = {"Musician"};
} strti;

//virtual table
struct StrVtbl {
    strTI* ti = &strti;
    void (String::* fplay)();
    // void (String::* play)() = &String::play;
} strvtbl;


// String inherit from base
struct String : public Musician {
	void play() {
		std::cout << "string" << std::endl;
	}
	StrVtbl* vptr = &strvtbl; 
};


//type info
struct braTI {
    std::string name = "Brass";
    std::string base[1] = {"Musician"};
} brati;


//virtual table
struct BraVtbl {
    braTI* ti = &brati;
    void (Brass::* fplay) ();
} bravtbl;

// Brass inherit from base
struct Brass : public Musician {
	void play() {
		std::cout << "Brass" << std::endl;
	}
	BraVtbl* vptr = &bravtbl;
};


//type info
struct vioTI {
    std::string name = "Violin";
    std::string base[2] = {"String", "Musician"};
} vioti;

//virtual table
struct VioVtbl {
    vioTI* ti = &vioti;
    void (Violin::* play)();
} viovtbl;


//inherit from String
struct Violin : public String {
	void play() {
		std::cout << "voilin" << std::endl;
	}
	VioVtbl* vptr = &viovtbl;
};

//type info
struct gtrTI {
    std::string name = "Guitar";
    std::string base[2] = {"String", "Musician"};
    } gtrti;


//virtual table
struct GtrVtbl {
    gtrTI* ti = &gtrti;
    void (Guitar::* play)();
} gtrvtbl;


struct Guitar : public String {
	void play() {
		std::cout << "guitar" << std::endl;
	}
	GtrVtbl* vptr = &gtrvtbl;
};

//type info
struct pianTI {
    std::string name = "Piano";
    std::string base[2] = {"String", "Musician"};
    } pianti;

//virtual table
struct PianVtbl {
    pianTI* ti = &pianti;
    void (Piano::* play)();
} pianvtbl;


struct Piano : public String {
	void play() {
		std::cout << "piano" << std::endl;
	}
	PianVtbl* vptr = &pianvtbl;
};


//type info
struct fluTI {
    std::string name = "Flute";
    std::string base[2] = {"Brass", "Musician"};
} fluti;

//virtual table
struct FluVtbl {
    fluTI* ti = &fluti;
    void (Flute::* play)();
} fluvtbl;

//inherit from Brass
struct Flute : public Brass {
	void play() {
		std::cout << "flute" << std::endl;
	}
	FluVtbl* vptr = &fluvtbl;
};


//type info
struct trumTI {
    std::string name = "Trumpet";
    std::string base[2] = {"Brass", "Musician"};
} trumti;

//virtual table
struct TrumVtbl {
    trumTI* ti = &trumti;
    void (Trumpet::* play) ();
} trumvtbl;

struct Trumpet : public Brass {
	void play() {
		std::cout << "trumpet";
	}
	TrumVtbl* vptr = &trumvtbl;
};

//type info
struct trmbTI {
    std::string name = "Trumbone";
    std::string base[2] = {"Brass", "Musician"};
} trmbti;

//virtual table
struct TrmbVtbl {
    trmbTI* ti = &trmbti;
    void (Trumbone::* play)();
} trmbvtbl;

struct Trumbone : public Brass {
	void play() {
		std::cout << "trumbone" << std::endl;
	}
	TrmbVtbl* vptr = &trmbvtbl;
};

//type info
struct clarTI {
    std::string name = "Clarinet";
    std::string base[2] = {"Brass", "Musician"};
} clarti;

//virtual table
struct ClarVtbl {
    clarTI* ti = &clarti;
    void (Clarinet::* play)();
} clarvtbl;

struct Clarinet : public Brass {
	void play() {
		std::cout << "clarinet" << std::endl;
	}
	ClarVtbl* vptr = &clarvtbl;
};