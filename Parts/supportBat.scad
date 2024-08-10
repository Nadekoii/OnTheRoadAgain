union(){
    translate([28,0,0]){
        difference(){
            cube([32,7,2]);
            translate([2.5,3.5,0]){
                cylinder(r=1.5,h=6); 
            }
            translate([29.5,3.5,0]){
                cylinder(r=1.5,h=6); 
            }
        }
    }
    translate([0, 7, 0]) {
        difference() {
            translate([14.5,0,0]){
                cube([59, 2, 40]);
            }
            translate([19, 2, 8.5]) { // Center of the wall
                rotate([90, 0, 0]) {
                    cylinder(r=2.5,h=6); 
                }
            }
            translate([59, 2, 8.5]) { // Center of the wall
                rotate([90, 0, 0]) {
                    cylinder(r=2.5,h=6); 
                }
            }
            translate([19, 2, 32.5]) { // Center of the wall
                rotate([90, 0, 0]) {
                    cylinder(r=2.5,h=6); 
                }
            }
            translate([59, 2, 32.5]) { // Center of the wall
                rotate([90, 0, 0]) {
                    cylinder(r=2.5,h=6); 
                }
            }
        }
    }
}