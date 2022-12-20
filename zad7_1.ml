module type Numerical_type = sig
  type num_type
  val to_float : num_type -> float
end;;

module type Point =
sig
  type 'a t
  val distance: 'a t * 'a t -> float
  val create: 'a*'a*'a -> 'a t
end;;

module Point_Implementation (N: Numerical_type) : Point = 
struct
  type 'a t = {x:N.num_type; y:N.num_type; z:N.num_type}
  let distance ((m:('a t)),(n:('a t))) = sqrt((N.to_float(m.x) -. N.to_float(n.x))**2. 
  +. (N.to_float(m.y) -. N.to_float(n.y))**2. +. (N.to_float(m.z) -. N.to_float(n.z))**2.)
  let create (x,y,z) = {t.x=x; t.y=y; t.z=z}
end;;

module Point_Int = Point_Implementation(struct type num_type = int
                            let to_float x = float_of_int(x) end);;              
module type Segment  =
sig
  type t 
  val length: t -> float
end;;

module Segment_Implementation : Segment = 
struct
  type t = Point.to_float
  let length (s:t) = 5.0
end;;