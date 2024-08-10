            difference(){
                cube([55,28,2]);
                //Troux pour l'Arduino
                translate([3,4,0]){
                    cylinder(r=2,h=6);
                }
                translate([52,4,0]){
                    cylinder(r=2,h=6);
                }
                //Troux pour support de la batterie:
                translate([27.5-13.5,26,0]){
                    cylinder(r=1.5,h=6); 
                }
                translate([27.5+13.5,26,0]){
                    cylinder(r=1.5,h=6); 
                }
            }