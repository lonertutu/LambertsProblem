
# Finding Velocities in the Lambert Problem

Two vectors are supplied: the vector of the Initial orbit and the final.

$r_1$ and $r_2$ determine the change in the true anomaly $\Delta \theta$.

$$ \cos{ \Delta \theta} = __r_1__ \dot __r_2__ \over r_1 r_2 $$

There are two cases to consider: prograde trajectories $(0 < i < 90^{\circ})$, and retrograde
trajectories $(90^{\circ}< i < 180^{\circ})$.

$$ \Delta \theta = \arccos{\frac{__r_1__ \dot __r_2__}{r_1 r_2}}$$ and if $(__r1__ \times __r2__)_z \ge 0$ - prograde trajectory

$$ \Delta \theta = \arccos{\frac{__r_1__ \dot __r_2__}{r_1 r_2}}$$ and if $(__r1__ \times __r2__)_z \l 0$ - retrograde trajectory

According to a theorem of Lambert, the transfer time $\Delta t$ from $P_1$
to $P_2$ is independent of the orbit’s eccentricity and depends only on the sum $r_1 + r_2$
of the magnitudes of the position vectors, the semimajor axis a and the length c of
the chord joining $P_1$ and $P_2$.

$$ __r_2__ = f__r_1__ g__v_1__ $$
$$ __v_2__ = \dot{f}__r_1__ \dor{g}__v_1__ $$
where g and f - Lagrange coefficients

Main link to study materials: Orbital Mechanics for Engineering Students by Howard D. Curtis