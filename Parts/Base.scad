union(){
    translate([0,70,0]){
        translate([6,4,0]){
            difference(){
                cube([61,92,2]);
                
                //Troux pour l'Arduino
                translate([6,4,0]){
                    cylinder(r=2,h=6);
                }
                translate([55,4,0]){
                    cylinder(r=2,h=6);
                }
                
                translate([6,26,0]){
                    cylinder(r=2,h=6);
                }
                translate([55,24,0]){
                    cylinder(r=2,h=6);
                }
                
                translate([51,75,0]){
                    cylinder(r=2,h=6);
                }
                translate([22,75,0]){
                    cylinder(r=2,h=6);
                }
                translate([6,82,0]){
                        cylinder(r=2,h=6);
                }
                translate([55,82,0]){
                        cylinder(r=2,h=6);
                }
                //Troux pour support de la batterie:
                translate([30.5-13.5,86+3.5,0]){
                    cylinder(r=1.5,h=6); 
                }
                translate([30.5+13.5,86+3.5,0]){
                    cylinder(r=1.5,h=6); 
                }
            }
        }
        
        //Troux pour les 2 grand roux
        translate([0,0,0]){
            difference(){
                cube([8,90,2]);
                translate([3,86,0]){
                        cylinder(r=2,h=6);
                }
                translate([3,78,0]){
                        cylinder(r=2,h=6);
                }
                translate([3,62,0]){
                        cylinder(r=2,h=6);
                }
                translate([3,38,0]){
                        cylinder(r=2,h=6);
                }
                translate([3,30,0]){
                        cylinder(r=2,h=6);
                }
            }
        }
        translate([65,0,0]){
            difference(){
                cube([8,90,2]);
                translate([5,86,0]){
                    cylinder(r=2,h=6);
                }
                translate([5,78,0]){
                    cylinder(r=2,h=6);
                }
                translate([5,62,0]){
                    cylinder(r=2,h=6);
                }
                translate([5,38,0]){
                    cylinder(r=2,h=6);
                }
                translate([5,30,0]){
                    cylinder(r=2,h=6);
                }    
            }
        }
    }
    union(){
        //Troux pour 1er roux
        translate([6,64,0]){
            difference(){
                cube([61,10,2]);
                translate([18,4,0]){
                   cylinder(r=2,h=6); 
                }
                translate([42,4,0]){
                   cylinder(r=2,h=6); 
                }
            }
        }
        translate([20.5,34,0]){
            difference(){
                cube([32,38,2]);
                translate([4,4,0]){
                   cylinder(r=2,h=6); 
                }
                translate([28,4,0]){
                   cylinder(r=2,h=6); 
                }
                translate([4,34,0]){
                   cylinder(r=2,h=6); 
                }
                translate([28,34,0]){
                   cylinder(r=2,h=6); 
                }
            }
        }
        translate([20.5,17,0]){
            difference(){
                cube([32,17,2]);
                translate([2.5,3.5,0]){
                   cylinder(r=1.5,h=6); 
                }
                translate([29.5,3.5,0]){
                   cylinder(r=1.5,h=6); 
                }
                translate([8,0,0]){
                    cube([16,2,2]);
                }   
            }
        }
    }
}