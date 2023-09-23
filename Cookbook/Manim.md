# Manim

> I doubt if I still have the energy to write the remaining tutorials...

## 3D-Scenes
> Author: Brandon Lin 林楠

> Date: 2023.03.17

> Written in Shanghai Jiao Tong University

```python
from manim import *

config.media_width = "75%"
config.verbosity = "WARNING"
```

### Scene and Animations
- ThreeDScene: Always use the `ThreeDScene` class when creating 3D animations. It provides essential methods for working with 3D objects and camera control.
- Basic methods:
    - `self.add()`
    - `self.play(..., run_time=NUM)` (I think for every animation, we can control its duration, but I haven't verify it yet)
    - `self.wait()`

```python
%%manim -qm Example

class Example(ThreeDScene):
    def construct(self):
        pass
```

### Axes et Camera
#### Axes
- Always use the `ThreeAxes(**axes_config)` class, define the range of the axes by yourself by changing the values in `x_range`, `y_range` and `z_range` 
- You can use `add_coordinate()` to mark the numbers on the axe
- Add labels at the end of the axes: `x_label = Tex("$x$").next_to(axes.x_axis.get_end(), RIGHT, buff=0.2)`
#### Camera
- Explication: 

![Explication](https://www.researchgate.net/publication/339500564/figure/fig1/AS:862793272131584@1582717354263/Spherical-coordinates-r-th-ph-radial-distance-r-azimuthal-angle-th-and-polar-angle-ph.ppm)

- Initialisation: `set_camera_orientation(phi=None, theta=None, gamma=None, zoom=None, focal_distance=None, frame_center=None, **kwargs)` (I actually never use `gamma`, conversely, I found `distance` extremely useful. See examples below)
- Begin continuous camera rotation around the scene: `begin_ambient_camera_rotation(rate=0.02, about='theta')`
    - This method begins an ambient rotation of the camera about the Z_AXIS, in the anticlockwise direction
    - PARAMETERS
        - rate (float) – The rate at which the camera should rotate about the Z_AXIS. Negative rate means clockwise rotation.
        - about (str) – one of 3 options: [“theta”, “phi”, “gamma”]. defaults to theta.
- Stop the continuous camera rotation: `stop_ambient_camera_rotation()`
- Move the camera to a new position: `move_camera(*args, **kwargs)`
- Default position

```python
%%manim -qm Example

class Example(ThreeDScene):
    def construct(self):
        axes_config = {
            "x_range": [-5, 5],
            "y_range": [-5, 5],
            "z_range": [-5, 5],
        }

        axes = ThreeDAxes(**axes_config).add_coordinates()
        self.add(axes)
        
        # Labels for x, y, and z axes
        x_label = Tex("$x$").next_to(axes.x_axis.get_end(), RIGHT, buff=0.2)
        y_label = Tex("$y$").next_to(axes.y_axis.get_end(), UP, buff=0.2)
        z_label = Tex("$z$").next_to(axes.z_axis.get_end(), UP, buff=0.2)
        self.add(x_label, y_label, z_label)
        self.wait(3)        
```

- An ideal observation place

```python
%%manim -qm Example

class Example(ThreeDScene):
    def construct(self):
        axes_config = {
            "x_range": [-5, 5],
            "y_range": [-5, 5],
            "z_range": [-5, 5],
        }

        axes = ThreeDAxes(**axes_config).add_coordinates()
        
        
        self.set_camera_orientation(phi=80*DEGREES,
                                    theta=-40*DEGREES,
                                    distance=6)
        
        self.add(axes)
        
        self.begin_ambient_camera_rotation(rate=0.9)
        self.wait(3)        
```

- An example of transformation from 2D to 3D
  
```py
%%manim -qm Example

class Example(ThreeDScene):
    def construct(self):
        axes_config = {
            "x_range": [-5, 5],
            "y_range": [-5, 5],
            "z_range": [-5, 5],
        }

        axes = ThreeDAxes(**axes_config)
        
        curve = ParametricFunction(lambda t: np.array([
            np.cos(t), np.sin(3*t), np.cos(5*t)
        ]), color=YELLOW, t_range=(-5, 5))
        
        self.add(axes, curve)
        self.move_camera(phi=60*DEGREES, run_time=3)
        self.begin_ambient_camera_rotation(rate=0.9)
        self.wait(3)
```

### Text
- Use `Text()` class to create normal text informations.
- Use `Tex()` class to create, use `$$` when typing math equations and symbols !
- Use `scale` to define its size.
- Use `rotate` to change its orientation.
- Changing the position:
    - `shift` and `move_to`, such as `text.shift(LEFT*2 + UP*4)`
    - `next_to`, such as `text.next_to(circle, RIGHT, buff=0.5)`

- Important : There are two ways that the text appear, the first example shows that the text inclining with the camera, while the second example shows the text as if it is separated from the scene.
  
```py
%%manim -qm Example
# Example 1 : Text oriented with the camera
class Example(ThreeDScene):
    def construct(self):
        text3d = Tex("Hello World!$2+3=5 \sum$").scale(2)
        text3d.rotate(PI/2, axis=RIGHT)
        
        self.set_camera_orientation(phi=80*DEGREES,
                                    theta=-40*DEGREES,
                                    distance=6)
        
        self.play(Write(text3d))
        self.wait()
```
```py
%%manim -qm Example
from manim import *
# Example 2 : Text not oriented with the camera
class Example(ThreeDScene):
    def construct(self):
        text = Tex("Hello World!").scale(2)
        text.shift(LEFT*2 + UP*3)
        
        self.set_camera_orientation(phi=70 * DEGREES, theta=-60 * DEGREES)
        
        # Add text to a 2D overlay, so it stays in front of the camera without any inclination
        self.add_fixed_in_frame_mobjects(text)
        self.play(Write(text)) # Without this line, it will appear directly.
        self.wait()
```

### Transformations

Apply various transformations to your 3D objects using methods.

Manim can apply various transformations to 3D objects just as it does for 2D objects. Common transformations like translation, scaling, and rotation can be applied to 3D objects using methods like `.animate` syntax for animations and ...
- `move_to()`, 
- `scale()`, 
- `rotate()`

```py
%%manim -qm Example

class Example(ThreeDScene):
    def construct(self):
        axes = ThreeDAxes()
        cube = Cube(color=YELLOW).scale(0.5).shift(LEFT)
        sphere = Sphere(radius=0.5, resolution=(30, 30)).shift(RIGHT)

        self.set_camera_orientation(phi=75 * DEGREES, theta=-45 * DEGREES, distance=8)

        # Adding 3D objects to the scene
        self.play(FadeIn(axes), FadeIn(cube), FadeIn(sphere))
        self.wait()

        # Translation
        self.play(
            cube.animate.shift(2 * UP + 2 * OUT),
            sphere.animate.shift(2 * DOWN + 2 * IN),
        )
        self.wait()

        # Scaling
        self.play(
            cube.animate.scale(2),
            sphere.animate.scale(1.5),
        )
        self.wait()

        # Rotation
        self.play(
            Rotate(cube, angle=PI, axis=RIGHT),
            Rotate(sphere, angle=PI, axis=UP),
        )
        self.wait()
```

### Primitives
Manim has built-in 3D primitives like `Sphere`, `Cone`, `Cylinder`, `Box`, `Torus`, and `Arrow3D`. You can use these to create more complex 3D objects.

```py
%%manim -qm Example

class Example(ThreeDScene):
    def construct(self):
        sphere = Sphere(radius=1, resolution=(30, 30))
        cone = Cone(base_radius=1, height=2, direction=OUT)
        cone.shift(LEFT*6 + UP*15)
        
        self.set_camera_orientation(phi=80*DEGREES,
                                    theta=-40*DEGREES,
                                    distance=6)
        
        self.add(sphere, cone)
        self.play(ApplyMethod(sphere.move_to, np.array([3, -2, 1])))
        self.wait()
```

### Curves and Paths
- `ParametricFunction` is a class in Manim that allows you to create curves or paths in 2D space using parametric equations. A parametric equation defines a curve by expressing the coordinates of each point on the curve as a function of a parameter, usually denoted by $t$.

- Define the curve: `curve = ParametricFunction(curve_func, t_range=[t_min, t_max])` 
    - Here: `curve_func` could be: `lambda t: np.array([func_1, func_2, func_3])`
    
    
- Transform between curves: `Transform(curve1, curve2)`

```py
%%manim -qm Example

class Example(ThreeDScene):
    def construct(self):
        axes_config = {
            "x_range": [-5, 5],
            "y_range": [-5, 5],
            "z_range": [-5, 5],
        }

        axes = ThreeDAxes(**axes_config)
        
        self.set_camera_orientation(phi=80*DEGREES,
                                    theta=-40*DEGREES,
                                    distance=6)
        
        self.begin_ambient_camera_rotation(rate=0.9)
        self.add(axes)
        
        curve = ParametricFunction(lambda t: np.array([
            np.cos(t), np.sin(3*t), np.cos(5*t)
        ]), color=YELLOW, t_range=(-5, 5))
        
        curve_new = ParametricFunction(lambda t: np.array([
            np.cos(5*t), np.sin(t), np.cos(3*t)
        ]), color=BLUE, t_range=(-5, 5))
        
        self.play(Write(curve), run_time=10)
        self.play(Transform(curve, curve_new), run_time=5)
        self.wait()
```

### Surfaces
> In the context of Manim, `ParametricSurface` is a class that was available in earlier versions to create 3D surfaces by defining a parametric function. In the latest version of Manim, the `ParametricSurface` class has been replaced by the `Surface` class, which is used for the same purpose.

Parametric surfaces are 3D objects defined by parametric equations for the $x$, $y$, and $z$ coordinates in terms of two parameters, usually denoted by $u$ and $v$. They can be used to create complex 3D objects like spheres, tori, or custom surfaces.

- Define the surface: `surface = Surface(surface_func, u_range=[u_min, u_max], v_range=[v_min, v_max], resolution=(NUM, NUM))`
    - The `resolution` affects the time used to produce the video.

```py
%%manim -qm Example
# Example of 3 surfaces
class Example(ThreeDScene):
    def construct(self):
        axes_config = {
            "x_range": [-5, 5],
            "y_range": [-5, 5],
            "z_range": [-5, 5],
        }

        axes = ThreeDAxes(**axes_config)
        
        self.set_camera_orientation(phi=80*DEGREES,
                                    theta=-40*DEGREES,
                                    distance=6)
        
        self.begin_ambient_camera_rotation(rate=0.9)
        self.add(axes)
        
        bowl = Surface(
            lambda u, v: np.array([
                np.cos(v)*u, np.sin(v)*u, u**2
            ]), v_range=(-5, 5), resolution=(10, 32)
        ) # "resolution" affects the time used to produce the video!
        
        HeatedSurface = Surface(
            lambda u, v: np.array([
                u, v, np.sin(v) + np.cos(v)
            ]), u_range=(-5, 5), v_range=(-5, 5), resolution=(15, 50)
        )
        
        PlaneSurface = Surface(
            lambda u, v: np.array([
                u, v, 2*u + 3*v -1
            ]), u_range=(-5, 5), resolution=(15, 50)
        )
        self.play(Write(bowl), run_time=3)
        self.play(Write(HeatedSurface), run_time=5)
        self.play(Write(PlaneSurface), run_time=3)
        self.wait()
```

### Grouping

`VGroup` (short for "Vectorized Group") is a class in Manim that's used to group multiple Mobjects (short for "Mathematical Objects") together. This allows you to treat a collection of Mobjects as a single entity, making it easier to manipulate, transform, and animate them simultaneously.

Some common use cases for`VGroup` include:

- Positioning: When you want to position multiple Mobjects relative to each other or in a specific arrangement, you can use a `VGroup` to move them together while preserving their relative positions.

- Scaling and Rotation: When you want to scale or rotate multiple Mobjects as a unit, you can use a `VGroup` to apply the transformation to all of its child Mobjects.

- Animation: When you want to animate multiple Mobjects simultaneously, you can use a `VGroup` to apply the animation to the entire group.

```py
%%manim -qm VGroupExample

class VGroupExample(Scene):
    def construct(self):
        circle = Circle(color=RED)
        square = Square(color=BLUE).scale(0.5)
        triangle = Triangle(color=YELLOW).scale(0.5).next_to(square, RIGHT, buff=0.5)

        # Create a VGroup containing the circle, square, and triangle
        group = VGroup(circle, square, triangle)

        # Position the group at the center of the screen
        group.move_to(ORIGIN)

        # Rotate the group by 45 degrees
        group.rotate(45 * DEGREES)

        self.play(FadeIn(group))
        self.wait()

        # Animate the group scaling up and down
        self.play(group.animate.scale(1.5))
        self.play(group.animate.scale(1/1.5))
        self.wait()
```

### References
There are no formally written references, thanks to:
- Video: https://www.youtube.com/watch?v=0YF9mkGkcgI
- Video: https://www.youtube.com/watch?v=FEtYAw3sI9Y&list=PLWOlLjdyZm2NQD1YZmEPB0dwbd0yKINAT&index=4