class Automobile {
    public: 
    // Constructors
    Automobile();
    Automobile (const std::string &c); // const is there to limit the amount of memory the string can use

    //Accessor Functions
    double get_gas_left () const;
    double get_current_speed () const;
    double get_odometer () const;
    double get_avg_mpg () const;
    std::string get_color () const;



};