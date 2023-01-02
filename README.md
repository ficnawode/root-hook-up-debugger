# cbmroot-starter

Experimenting with CBMRoot. 

Goals:
- try and generate a TOF plot
- find out how to get simulated and reconstructed data
- compile the macros and maybe hook up a debugger 

The first two targets have turned out to be relatively easy. I dug around in a fellow team member's old repositories and succesfully generated some fancy-looking plots (from the tof.C, momentum.C and event.C macros, respectively):

![TOF plot](docs/images/tof_plot.png "TOF plot from simulated data")
![Correlation reco x y](docs/images/corr_rec_pxpy.png "correlation between reconstructed momenta in the x and y direction")
![Correlation sim-reco x](docs/images/corr_x.png "correlation between simulated and reconstructed data in the x direction")


Data has been taken from a 3.3GeV Au-Au collision from the GSI `lustre` server.

Requires FairSoft, FairRoot and CBMRoot to run.

in order to run:
```
source <path-to-cbmroot-build-directory>/config.sh --prepend
```
then put the data in the `in/` directory and subsequently in the `macro/` directory, run:
```
ls ../in/* > filelist.txt
```
```
root <name-of-macro>
```
The macro will generate a .root file in the out directory.

Input files obtained via

```
scp -r virgo-debian10.hpc:/lustre/cbm/users/lubynets/cbm2atree/outputs/apr20_fr_18.2.1_fs_jun19p1/dcmqgsm_smm_pluto/auau/3.3agev/mbias/sis100_electron_target_25_mkm_psd_v18e_p3.3_56/AT2/*.analysistree.root .
```

Heavily based on macros by Julian Nowak at https://github.com/julnow/cbm_remote/tree/master/atree
