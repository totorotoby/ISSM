/*!\file Profiler.h
 * \brief: header file for node object
 */

#ifndef _PROFILER_H_
#define _PROFILER_H_

/*Headers:*/
#include "../shared/shared.h"
#include "../datastructures/datastructures.h"

/*Macros*/
#define TOTAL              0 /*Profiling Total time */
#define MPROCESSOR         1 /*Profiling Model processor*/
#define CORE               2 /*Profiling solution */
#define SOLVER             3 /*Profiling solution */
#define ADCORE             4 /*Profiling AD */
#define THERMALCORE			5 /*Profiling THERMAL */
#define HYDROLOGYCORE		6 /*Profiling HYDROLOGY */
#define STRESSBALANCECORE	7 /*Profiling STRESSBALANCE */
#define DAMAGECORE			8 /*Profiling DAMAGE */
#define MOVINGFRONTCORE		9 /*Profiling MOVINGFRONT */
#define MASSTRANSPORTCORE	10 /*Profiling MASSTRANSPORT */
#define MMEMASSTRANSPORTCORE 11 /*Profiling MMEMASSTRANSPORT */
#define OCEANTRANSPORTCORE	12 /*Profiling OCEANTRANSPORT */
#define SMBCORE				13 /*Profiling SMB */
#define GROUNDINGLINECORE	14 /*Profiling GROUDINGLINE MIGRATION */
#define ESACORE				15 /*Profiling ESA */
#define SLRCORE				16 /*Profiling SLR */
#define DEBRISCORE                              17 /*Profiling DEBRIS */
#define SAMPLINGCORE	19 /*Profiling SAMPLING */
#define MPISERIAL				19 /*Profiling MPISerial */
#define SEDLOOP				20 /*Profiling MPISerial */
#define SEDMatrix				21 /*Profiling MPISerial */
#define SEDUpdate				22 /*Profiling MPISerial */
#define EPLLOOP				23 /*Profiling MPISerial */
#define EPLMasking			24 /*Profiling MPISerial */
#define EPLMatrices			25 /*Profiling MPISerial */
#define EPLUpdate				26 /*Profiling MPISerial */
#define MAXPROFSIZE			27 /*Used to initialize static arrays*/

class Profiler: public Object{

	public:
		IssmPDouble flops[MAXPROFSIZE];
		IssmPDouble flops_start[MAXPROFSIZE];
		IssmPDouble memory[MAXPROFSIZE];
		IssmPDouble memory_start[MAXPROFSIZE];
		IssmPDouble time[MAXPROFSIZE];
		IssmPDouble time_start[MAXPROFSIZE];
		bool        running[MAXPROFSIZE];
		bool        used[MAXPROFSIZE];

		/*Profiler constructors, destructors */
		Profiler();
		~Profiler();

		/*Object virtual functions definitions*/
		Object *copy();
		void    DeepEcho();
		void    Echo();
		int     Id();
		void    Marshall(MarshallHandle* marshallhandle);
		int     ObjectEnum();

		/*Profiler routines*/
		IssmPDouble  TotalFlops(int tag);
		IssmPDouble  TotalTime(int tag);
		int          TotalTimeModHour(int tag);
		int          TotalTimeModMin(int tag);
		int          TotalTimeModSec(int tag);
		IssmPDouble  Memory(int tag);
		void         Start(int tagenum,bool dontmpisync=true); /*Do not call MPI barrier by default to save some ms*/
		void         Stop(int tagenum, bool dontmpisync=true); /*Do not call MPI barrier by default to save some ms*/
		bool         Used(int tagenum);
};

#endif  /* _PROFILER_H_ */
